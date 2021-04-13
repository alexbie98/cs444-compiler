set -e

make
rm output/*

cp stdlib/5.0/runtime.s output/

./joosc assignment_testcases/a5/J1_01.java stdlib/5.0/java/io/OutputStream.java stdlib/5.0/java/io/PrintStream.java stdlib/5.0/java/io/Serializable.java stdlib/5.0/java/lang/Boolean.java stdlib/5.0/java/lang/Byte.java stdlib/5.0/java/lang/Character.java stdlib/5.0/java/lang/Class.java stdlib/5.0/java/lang/Cloneable.java stdlib/5.0/java/lang/Integer.java stdlib/5.0/java/lang/Number.java stdlib/5.0/java/lang/Object.java stdlib/5.0/java/lang/Short.java stdlib/5.0/java/lang/String.java stdlib/5.0/java/lang/System.java stdlib/5.0/java/util/Arrays.java

for file in output/*.s
do
  /u/cs444/bin/nasm -O1 -f elf -g -F dwarf "$file"
done

ld -melf_i386 -o main output/*.o

