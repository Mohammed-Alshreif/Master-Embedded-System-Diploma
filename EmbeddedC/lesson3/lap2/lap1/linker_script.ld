/*ENG. MOHAMMED ALSHREIF*/

MEMORY
{
flash (RX): ORIGIN = 0x08000000 , LENGTH = 128k
sram (RWX): ORIGIN = 0x20000000 , LENGTH = 20k
}

SECTIONS
{
 .text :
 {
   *(.vectors*)
   *(.text*)
   *(.rodata)
   
 }> flash
 
 .data :
 {
  *(.data)
 }> flash
 
 .bss :
 {
  *(.bss)
 }> sram
 
}
