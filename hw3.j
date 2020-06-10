.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
ldc 3
ldc 4
ldc 5
ldc 8
ineg
iadd
imul
isub
ldc 10
ldc 7
idiv
isub
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
ldc 3
ldc 4
ldc 5
ldc 8
ineg
iadd
imul
isub
ldc 10
ldc 7
idiv
isub
ldc 4
ineg
ldc 3
irem
isub
ifgt branch_0
iconst_0
goto branch_1
branch_0:
iconst_1
branch_1:
iconst_1
iconst_1
ixor
iconst_1
iconst_1
iconst_0
ixor
ixor
iand
ior
ifne branch_2
ldc "false"
goto branch_3
branch_2:
ldc "true"
branch_3:
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
ldc 3.000000
ldc 4.000000
ldc 5.000000
ldc 8.000000
fneg
fadd
fmul
fsub
ldc 10.000000
ldc 7.000000
fdiv
fsub
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(F)V
ldc 3.000000
ldc 4.000000
ldc 5.000000
ldc 8.000000
fneg
fadd
fmul
fsub
ldc 10.000000
ldc 7.000000
fdiv
fsub
ldc 4.000000
fneg
fsub
ifgt branch_4
iconst_0
goto branch_5
branch_4:
iconst_1
branch_5:
iconst_1
iconst_1
ixor
iconst_1
iconst_1
iconst_0
ixor
ixor
iand
ior
ifne branch_6
ldc "false"
goto branch_7
branch_6:
ldc "true"
branch_7:
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
return
.end method
