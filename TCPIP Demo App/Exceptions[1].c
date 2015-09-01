

#include <assert.h>
#include <sys/appio.h>

// General Exceptions - Cause register
// The pending interrupts field consists of bits, each corresponding to a separate interrupt
//   level.  If a bit is '1', then an interrupt has occurred and still needs to be serviced.  The exception
//   code field consists of a 4 bit value that tells us what exception occurred to cause the interrupt.

// Pending Interrupts - 10 - 15
// Exception Code     -  2 -  5

// Status - Status register
// The interrupt mask allows there to be multiple levels of interrupts to be masked instead of
//   requiring all interrupts to be masked at once.  There are a totol of 8 bits in the interrupt mask
//   allowing a total of 8 interrupt levels: 3 software levels and 5 hardware levels.  If a bit is set to '0',
//   that level of interrupts is disabled.  If a bit is set to '1', that level of interrupts is enabled.
// I.E.: 0 - All interrupts are disabled.
//       1 - All interrupts are allowed.
// K/U:  0 - The Kernel is in control of the processor.
//       1 - The User is in control of the processor.
// Interrupt Mask      - 8 - 15
// Current Int Enable  - 0 - 1   - I.E(0), K/U(1)
// Previous Int Enable - 2 - 3   - I.E(2), K/U(3)
// Old Int Enable      - 4 - 5   - I.E(4), K/U(5)


typedef enum {
	GE_INT     = 0,		// external interrupt
	GE_ADDRL   = 4,		// address error exception (load or instruction fetch)
	GE_ADDRS   = 5,		// address error exception (store)
	GE_IBUS    = 6,		// bus error on instruction fetch
	GE_DBUS    = 7,		// bus error on data load on store
	GE_SYSCALL = 8,		// syscall exception
	GE_BKPT    = 9,		// breakpoint exception
	GE_RI      = 10,		// reserved instruction exception
	GE_OVF     = 12		// arithmetic overflow exception
} GeneralExceptionCause;


static unsigned int _excep_code;
static unsigned int _excep_addr;


void _general_exception_handler (unsigned cause, unsigned status)
{
	asm volatile("mfc0 %0,$13" : "=r" (_excep_code));
	asm volatile("mfc0 %0,$14" : "=r" (_excep_addr));

	unsigned int ec = (_excep_code >> 2) & 0xF;
	unsigned int pi = (_excep_code >> 10) & 0x3F;

	DBPRINTF("Exception. Code:%X at %X\n", ec, _excep_addr);
	assert(0);
}
