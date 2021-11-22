SviTools, version 1.2
---------------------

SviTools is developed by Johan Winge, copyright (C) 2014-2016.
It is released according to the revised BSD license: see the file COPYING.

SviTools is a tool for working with data cassettes for the Spectravideo
(SVI) 318 and 328 home computers. It is a replacement of the older programs
SviCas2Wav and SviWav2Cas, and also implements some of the functionality of
SviCasMan. With SviTools you can read and write to a number of different
formats:
 * WAV files, containing the raw sound as stored on tape.
 * CAS files, for use in emulators, such as BlueMSX.
 * The index files as used by the SVITAPE program.
Additionally, it will enable you to import text and binary files and store
them as Spectravideo files inside a cassette container.

The latest source code as well as binary distributions can be downloaded
from SourceForge:
  http://sourceforge.net/projects/svitools/

How to use SviTools
-------------------

Please run svitools with the -h parameter to see a full list of available
parameters, along with explanations of what they do.

Additional notes on reading WAV files
-------------------------------------

Starting from version 1.1, SviTools uses a more robust algorithm for
decoding WAV files, and will output more detailed information, making it
easier to analyze and successfully convert old degraded tapes. First,
a list of continuous sequences of readable bits will be output, followed
by a list of the files or data blocks which could be read from those
signals. A typical successful output may look as follows:

Signal:     from        to  periods  error  bytes
           10340    103421     3324  0.121     17
          133151   1227136    35308  0.089   3570
Found: hatman c  3570 bytes    (crc:bb55)

Two continuous signals could be seen: from the first (ranging from sample
10340 to 103421) we could read 17 bytes. (The reported error value represents
the average quality of the signal: 0.121 is somewhat high, but is probably
okay here; a value below 0.050 is very good. In general, don't pay too much
attention to this value.)

From these signals, we could read a file, "hatman", with a checksum of bb55.
To be sure that your converted tapes are error free, I would recommend that
you, if possible, convert different tapes containing the same data. The
checksums can then be used to make certain that the resulting files are
identical.

Very commonly you may see analyses similar to this:

Signal:     from        to  periods  error  bytes
           10706    103421     3315  0.144     17
          133151    440425    10035  0.109    763
          440447    475249     1134  0.109  no sync
          475271    885316    13167  0.103  no sync
          936436    990014     1693  0.097  no sync
Found: hatman c   763 bytes    (crc:42d0)
Warning: Data block ended with 0 zero bytes. Expected at least 10!

When "no sync" is reported, it means that there seems to be data there, but
no synchronization header could be found, and hence no bytes could be read.
Such signal blocks could be noise that is accidentally read as data, or it
could be the end of an old partially overwritten file, or, as in this case,
it could be that the tape was in such a bad condition that the decoding
algorithm accidentally lost track of the signal prematurely. The file list
confirms that something is not right: "hatman" ends in a way it shouldn't.
By looking at the size of the file (763 bytes) you can identify what signal
block it was read from, namely the one ending (prematurely) at sample 440425.

Another error will look like this:

Signal:     from        to  periods  error  bytes
           10340    103421     3176  0.115     16
Warning: Reading of bytes ended prematurely at sample 102957.
Perceived bits: ...101101001100110100000110000001110100001101101001100001001101110011
          133151   1227136    33852  0.086  no sync
Found: <-data->    16 bytes    (crc:8a25)
Note: Data block did not end with 0.

This means that something is probably amiss at sample 102957, or somewhere
before that. An audio editing program such as Audacity will let you show the
wave form, and zoom in on different positions in the file, which may be useful
to analyze why the algorithm failed at a particular position. Small isolated
glitches can then be manually corrected (although it is a tedious process). 

In the case of errors, you may also try to experiment with varying the -z
parameter. If you are lucky, you may be able to decode a degraded tape that way.
Again, if possible, locate a different copy of the tape, and convert that too,
and then compare the checksums to confirm that the files actually are identical.

