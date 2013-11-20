.486
 
.MODEL FLAT, STDCALL
 
;OPTION CASEMAP:NONE
 
;INCLUDE C:\masm32\include\windows.inc
; .MMX  
.CODE
 




 sort proc tab_ptr: PTR DWORD, amount:DWORD
        
       pusha
	  
        mov ecx, amount				;przeœlij do rejestru iloœæ elementó w tablicy
        mov edx, tab_ptr			;przeœlij do rejestru wskaŸnik na pierwszy element
        bs_o:
			 xor ebp,ebp			;zerujemy ebp, który pos³u¿y do iteracji
			bs_i:
					mov eax, DWORD PTR [edx+ebp*4+4]
					cmp DWORD PTR [edx+ebp*4],eax
				jb @F
					xchg eax,DWORD PTR [edx+ebp*4]
					mov DWORD PTR [edx+ebp*4+4],eax
				@@:
					add ebp,1
					cmp ebp,ecx
			jb bs_i
        loop bs_o
        


		popa
		leave
        retn 
 
		

		
 



       ; popa
		;leave
       ; retn

 sort ENDP
 
 
 END
 
 
 
 
  ;DllEntry PROC hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD
;mov eax, TRUE
;ret 3
;DllEntry ENDP
 
 
 

 
 
;MojaFunkcja proc arg: DWORD
;mov eax, arg
;INC eax
 ;ret
;MojaFunkcja endp
 
;END DllEntry