000007FEFD7D8960 <kernelbase.OpenProcess | sub rsp,68                                 |
000007FEFD7D8964                         | xor r9d,r9d                                |
000007FEFD7D8967                         | movsxd rax,r8d                             |
000007FEFD7D896A                         | mov dword ptr ss:[rsp+30],30               | 30:'0'
000007FEFD7D8972                         | mov qword ptr ss:[rsp+28],r9               | r9:mainCRTStartup
000007FEFD7D8977                         | mov qword ptr ss:[rsp+20],rax              | rax:BaseThreadInitThunk
000007FEFD7D897C                         | mov qword ptr ss:[rsp+38],r9               | r9:mainCRTStartup
000007FEFD7D8981                         | test edx,edx                               |
000007FEFD7D8983                         | jne kernelbase.7FEFD7DD960                 |
000007FEFD7D8989                         | mov dword ptr ss:[rsp+48],r9d              |
000007FEFD7D898E                         | mov qword ptr ss:[rsp+40],r9               | r9:mainCRTStartup
000007FEFD7D8993                         | mov qword ptr ss:[rsp+50],r9               | r9:mainCRTStartup
000007FEFD7D8998                         | mov qword ptr ss:[rsp+58],r9               | r9:mainCRTStartup
000007FEFD7D899D                         | mov edx,ecx                                |
000007FEFD7D899F                         | lea r9,qword ptr ss:[rsp+20]               | r9:mainCRTStartup
000007FEFD7D89A4                         | lea r8,qword ptr ss:[rsp+30]               |
000007FEFD7D89A9                         | lea rcx,qword ptr ss:[rsp+88]              |
000007FEFD7D89B1                         | call qword ptr ds:[<&ZwOpenProcess>]       |
000007FEFD7D89B7                         | test eax,eax                               |
000007FEFD7D89B9                         | js kernelbase.7FEFD7D1E52                  |
000007FEFD7D89BF                         | mov rax,qword ptr ss:[rsp+88]              | rax:BaseThreadInitThunk
000007FEFD7D89C7                         | add rsp,68                                 |
000007FEFD7D89CB                         | ret                                        |
000007FEFD7D89CC                         | xor eax,eax                                |
000007FEFD7D89CE                         | add rsp,20                                 |
000007FEFD7D89D2                         | pop rbx                                    |
000007FEFD7D89D3                         | ret                                        |


fffff800`02cc3d80 4883ec08        sub     rsp,8
fffff800`02cc3d84 55              push    rbp
fffff800`02cc3d85 4881ec58010000  sub     rsp,158h
fffff800`02cc3d8c 488dac2480000000 lea     rbp,[rsp+80h]
fffff800`02cc3d94 48899dc0000000  mov     qword ptr [rbp+0C0h],rbx
fffff800`02cc3d9b 4889bdc8000000  mov     qword ptr [rbp+0C8h],rdi
fffff800`02cc3da2 4889b5d0000000  mov     qword ptr [rbp+0D0h],rsi
fffff800`02cc3da9 fb              sti
fffff800`02cc3daa 65488b1c2588010000 mov   rbx,qword ptr gs:[188h]
fffff800`02cc3db3 0f0d8bd8010000  prefetchw [rbx+1D8h]
fffff800`02cc3dba 0fb6bbf6010000  movzx   edi,byte ptr [rbx+1F6h]
fffff800`02cc3dc1 40887da8        mov     byte ptr [rbp-58h],dil
fffff800`02cc3dc5 c683f601000000  mov     byte ptr [rbx+1F6h],0
fffff800`02cc3dcc 4c8b93d8010000  mov     r10,qword ptr [rbx+1D8h]
fffff800`02cc3dd3 4c8995b8000000  mov     qword ptr [rbp+0B8h],r10
fffff800`02cc3dda 4c8d1d3d010000  lea     r11,[nt!KiSystemServiceStart (fffff800`02cc3f1e)]
fffff800`02cc3de1 41ffe3          jmp     r11