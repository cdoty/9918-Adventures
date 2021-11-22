The project works without modifications with any supported card. The card can be inserted in any supported slot and doesn't depend on interrupts. MAME is a good way to test these cards.
  
* Self modifying code is used to support the card being inserted into any slot. Using "sta $ADDR, x" causes a read before write, which resets the register write.
* Enabling the interrupt, on the VDP, causes issues on the Apple IIgs. I think the Apple IIe would support using the IRQ interrupt.
* [diskm8](https://paleotronic.com/diskm8/) is used to support writing to disk images. DOS 3.3 is used for simplicity.

