public _fmod

.code

_fmod proc
	fld     qword ptr [r8]
	fld     qword ptr [rdx]
L1:
	fprem
	fstsw   ax
	test    ax, 0400H
	jnz     L1
	fstp    tbyte ptr [rcx]
	fstp    st(0)
	ret
_fmod endp

end
