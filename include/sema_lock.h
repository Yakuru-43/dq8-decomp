#ifndef SEMA_LOCK_H
#define SEMA_LOCK_H

// C++ only. A scoped lock on a semaphore id that another thread may change
// (sound streams): waits in the constructor, signals in the destructor, each only
// when the id is > 0. The object lives on the stack (`sw` of &id at the frame
// top) and every return path re-reads the id: `lw $v1,N($sp); lw $v0,0($v1);
// blez; jal SignalSema; lw $a0,0($v1)`. Compile with
// `// flags: -Cpp_exceptions off`; tools/set_abi.py drops the uncalled
// out-of-line destructor the way CodeWarrior's linker did.

extern "C" {
s32 WaitSema(s32 sema_id);
s32 SignalSema(s32 sema_id);
}

class SemaLock {
public:
    SemaLock(volatile s32 *sema) : m_sema(sema) { // thread-shared
        if (*m_sema > 0) {
            WaitSema(*m_sema);
        }
    }
    ~SemaLock() {
        if (*m_sema > 0) {
            SignalSema(*m_sema);
        }
    }

private:
    volatile s32 *m_sema; // thread-shared: the id another thread may change
};

#endif
