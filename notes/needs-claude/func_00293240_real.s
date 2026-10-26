00293240 27BDFF00  addiu       $sp, $sp, -0x100
00293244 24020002  addiu       $v0, $zero, 0x2
00293248 FFBF0070  sd          $ra, 0x70($sp)
0029324C 7FB50060  sq          $s5, 0x60($sp)
00293250 7FB40050  sq          $s4, 0x50($sp)
00293254 0080A82D  daddu       $s5, $a0, $zero
00293258 7FB30040  sq          $s3, 0x40($sp)
0029325C 7FB20030  sq          $s2, 0x30($sp)
00293260 7FB10020  sq          $s1, 0x20($sp)
00293264 7FB00010  sq          $s0, 0x10($sp)
00293268 8C83058C  lw          $v1, 0x58C($a0)
0029326C 8C7000E8  lw          $s0, 0xE8($v1)
00293270 0C0A4A58  jal         func_292960
00293274 AC6200E8  sw          $v0, 0xE8($v1)
00293278 8EA2058C  lw          $v0, 0x58C($s5)
0029327C AC5000E8  sw          $s0, 0xE8($v0)
00293280 8EA4058C  lw          $a0, 0x58C($s5)
00293284 0C0D7964  jal         func_35E590
00293288 0000A02D  daddu       $s4, $zero, $zero
0029328C 3C040042  lui         $a0, 0x42
00293290 0040282D  daddu       $a1, $v0, $zero
00293294 24841AD0  addiu       $a0, $a0, 0x1AD0
00293298 27A60080  addiu       $a2, $sp, 0x80
0029329C 24070020  addiu       $a3, $zero, 0x20
002932A0 24080001  addiu       $t0, $zero, 0x1
002932A4 0000482D  daddu       $t1, $zero, $zero
002932A8 0000502D  daddu       $t2, $zero, $zero
002932AC 240BFFFF  addiu       $t3, $zero, -0x1
002932B0 0C0D6588  jal         func_359620
002932B4 FFA00000  sd          $zero, 0x0($sp)
002932B8 0040882D  daddu       $s1, $v0, $zero
002932BC 10000017  b           . + 4 + (0x17 << 2)
002932C0 0000982D  daddu       $s3, $zero, $zero
002932C4 3C040044  lui         $a0, 0x44
002932C8 00131880  sll         $v1, $s3, 2
002932CC 8C420368  lw          $v0, 0x368($v0)
002932D0 00431021  addu        $v0, $v0, $v1
002932D4 8C450030  lw          $a1, 0x30($v0)
002932D8 0C0ABFEC  jal         func_2AFFB0
002932DC 248492A0  addiu       $a0, $a0, -0x6D60
002932E0 0040802D  daddu       $s0, $v0, $zero
002932E4 10000007  b           . + 4 + (0x7 << 2)
002932E8 0000902D  daddu       $s2, $zero, $zero
002932EC 005D1021  addu        $v0, $v0, $sp
002932F0 8C440080  lw          $a0, 0x80($v0)
002932F4 8C820000  lw          $v0, 0x0($a0)
002932F8 50500011  beql        $v0, $s0, . + 4 + (0x11 << 2)
002932FC 0000282D  daddu       $a1, $zero, $zero
00293300 26520001  addiu       $s2, $s2, 0x1
00293304 0251102A  slt         $v0, $s2, $s1
00293308 5440FFF8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
0029330C 00121080  sll         $v0, $s2, 2
00293310 16800005  bnez        $s4, . + 4 + (0x5 << 2)
00293314 00000000  nop
00293318 26730001  addiu       $s3, $s3, 0x1
0029331C 2A620004  slti        $v0, $s3, 0x4
00293320 5440FFE8  bnel        $v0, $zero, . + 4 + (-0x18 << 2)
00293324 8EA2058C  lw          $v0, 0x58C($s5)
00293328 328300FF  andi        $v1, $s4, 0xFF
0029332C 24020001  addiu       $v0, $zero, 0x1
00293330 50620009  beql        $v1, $v0, . + 4 + (0x9 << 2)
00293334 02A0202D  daddu       $a0, $s5, $zero
00293338 10000010  b           . + 4 + (0x10 << 2)
0029333C 0000102D  daddu       $v0, $zero, $zero
00293340 0C0D76EC  jal         func_35DBB0
00293344 0000302D  daddu       $a2, $zero, $zero
00293348 1040FFED  beqz        $v0, . + 4 + (-0x13 << 2)
0029334C 00000000  nop
00293350 1000FFEF  b           . + 4 + (-0x11 << 2)
00293354 64140001  daddiu      $s4, $zero, 0x1
00293358 0C0A4AA4  jal         func_292A90
0029335C 00000000  nop
00293360 0C0A49B4  jal         func_2926D0
00293364 02A0202D  daddu       $a0, $s5, $zero
00293368 0C0A4534  jal         func_2914D0
0029336C 02A0202D  daddu       $a0, $s5, $zero
00293370 0C0A44B0  jal         func_2912C0
00293374 02A0202D  daddu       $a0, $s5, $zero
00293378 24020001  addiu       $v0, $zero, 0x1
0029337C DFBF0070  ld          $ra, 0x70($sp)
00293380 7BB50060  lq          $s5, 0x60($sp)
00293384 7BB40050  lq          $s4, 0x50($sp)
00293388 7BB30040  lq          $s3, 0x40($sp)
0029338C 7BB20030  lq          $s2, 0x30($sp)
00293390 7BB10020  lq          $s1, 0x20($sp)
00293394 7BB00010  lq          $s0, 0x10($sp)
00293398 03E00008  jr          $ra
0029339C 27BD0100  addiu       $sp, $sp, 0x100
