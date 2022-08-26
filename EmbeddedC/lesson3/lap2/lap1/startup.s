/*mohammed Alshrief*/
.section .vectors
.word 0x20001000
.word reset
.word vectorhandler
.word vectorhandler

.section .text
reset:
	bl main
	b .
.thumb_func

vectorhandler:
	b reset