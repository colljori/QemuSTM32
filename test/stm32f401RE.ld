/* Program Entry, set to mark it as "used" and avoid gcc warnings */
ENTRY(ResetHandler)

/* Memory Spaces Definitions */
MEMORY
{
	RAM      (RWX) : ORIGIN = 0x20000000, LENGTH = 512K
	FLASH    (RX)  : ORIGIN = 0x08000000, LENGTH = 96K
}
