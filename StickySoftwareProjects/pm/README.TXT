PartitionMagic by PowerQuest
Version 3.04

Copyright (c) 1994-1997, PowerQuest Corporation
All Rights Reserved. Patents Pending.

This file explains changes made since the printing of the manual.


TABLE OF CONTENTS
-----------------

1.  License Types
2.  Updates
3.  Technical Support Issues
4.  General Usage Notes
5.  FAT32 Usage Notes
6.  Boot Manager vs. PQ Boot
7.  Windows NT and the Partition Copy function
8.  MagicMover from PowerQuest
9.  Security Problems Using Shared Drive Letters Under Windows 95
10. Partition Magician Newsletter


1. License Types
----------------

The Personal License Version is a machine-specific license that allows
modifications on one specific computer.  See the *User Guide* for the license
agreement.

The Pack License Version is available for use on a specific number of
computers; refer to the specific license for the number of active users
allowed.

The Professional License Version is available for modifying an unlimited
number of computers, one computer at a time.

The Enterprise Version is available for organizations requiring remote or
unattended configuration capabilities at multiple sites.

For information on the Pack, Professional or Enterprise Versions of
PartitionMagic, contact PowerQuest Corporate Sales at (801) 226-8977.


2. Updates
----------

To consistently give you the best available version of PartitionMagic, minor
updates are provided periodically.  We recommend that you check regularly our
home page (www.powerquest.com), FTP site (ftp.powerquest.com), BBS
(801-226-5608) or CompuServe (OS2AVENDOR, Other Vendors section) for the
latest bug fixes and minor improvements.


3. Technical Support Issues
---------------------------

A. To run PartitionMagic 3.0 on a computer that has ONLY Windows NT do the
following:

-Boot the computer into Windows NT.
-Install PartitionMagic 3.0 to the hard drive. 
-Create a bootable DOS floppy diskette.
-Copy PQMAGICT.EXE (PartitionMagic text mode version) to the bootable DOS
diskette. 
-Exit Windows NT, reboot your computer using the DOS bootable diskette, type
A:\PQMAGICT and press Enter.

B. If you are unable to access your CD-ROM drive after partitioning your hard
drive see page 173 in the PartitionMagic 3.0 manual. 

C. If PartitionMagic does not start properly or your computer locks up when
starting PartitionMagic see page 170 in the PartitionMagic manual for
information on freeing up conventional memory.   If the steps listed on page
170 do not solve the problem, try running PartitionMagic with the /NSS switch
(PQMAGIC /NSS).

D.  If you are receiving Error #110 and have an HP Pavilion, HP Vectra or
Digital Computer, please run PARTINFO according to the instructions on page
197 in the PartitionMagic 3.0 manual and contact  PowerQuest Technical
Support (801-226-6834) for instructions on how to solve the problem. 


4. General Usage Notes
----------------------

- Don't forget to backup your hard drive before using PartitionMagic.  While
PartitionMagic has been thoroughly tested and is quite safe, power failure,
operating system bugs, and hardware design bugs can put your data at risk. No
software program, including PartitionMagic, is perfect. Before using any
utility that makes such extensive changes to your hard drive, you should
backup your data.

- If you use Windows 3.1 and find that your mouse does not work in 
PartitionMagic, a Microsoft compatible mouse driver is supplied with
PartitionMagic.  To access the mouse driver exit to DOS and type
"C:\PQMAGIC\MOUSE" or insert this line in your AUTOEXEC.BAT file.

- If you run PartitionMagic from DOS:  Turn off 3rd party disk caches.
Deactivate or unload any TSR programs that access or modify the partitions
being changed.  Do not run PartitionMagic from a compressed drive.

- After using PartitionMagic, it is normal to get an error message when
starting Windows 3.1 stating that the swap file is corrupt.  Windows 3.1 is
designed knowing that disk utilities may move the clusters of the swap file. 
When a move is detected, the error message is given.  To fix the swap file, 
click on the 386 Enhanced icon in Control Panel, then on the Virtual Memory
button then delete the swap file and create it again. 

- This release of PartitionMagic handles ASCII filenames.  PartitionMagic
does not yet handle double byte character sets such as Japanese, resulting in
two known limitations: (1) Converting a partition from FAT to HPFS can
produce incorrectly translated filenames.  (2) An attempt to specify or set
the Volume label may fail.

- Sometimes changes made by PartitionMagic confuse Windows NT 3.5x, which
then assigns drive letters incorrectly.  This bug is fixed in Windows NT 4.0.
NT 3.5x users should use Disk Administrator to assign the drive letters back
to the values you prefer.

- Progress bars are an estimation only and can pause for several minutes,
even though PartitionMagic is still working correctly.  If you think your
computer has locked up, please be patient and PartitionMagic will finish the
operation.


5. FAT32 Usage Notes
--------------------

- The following operating systems support FAT32:

  Windows 95B - OSR2
  Windows 97

- If you are using an Operating System that supports FAT32 together with an
operating system that doesn't support FAT32 (i.e. Windows 3.11, Windows 95,
Windows NT) you may wish to disable FAT32 support.  Operating systems that
don't support FAT32 will be unable to see FAT32 partitions.  FAT32 support
can be set in the preferences.  

- OS/2 does not support FAT32 partitions.  Also, if you convert a partition
to FAT32 and convert it back to FAT16, all OS/2 extended attributes (EAs)
will be lost.

- The minimum size for a FAT32 partition is about 260 MB.

- Please note that the memory requirement (16 MB) for modifying FAT32
partitions is true in most circumstances. However, in some extraordinary
circumstances more memory may be required.


6. Boot Manager vs. PQ Boot
---------------------------

PartitionMagic 3.04 ships with both Boot Manager by IBM and PQ Boot by
PowerQuest.

When you install Boot Manager, PartitionMagic will create a separate primary
partition and mark it active.  When the computer starts, Boot Manager
displays a startup menu that allows you to choose the partition to boot.

PQ Boot is a command line utility to switch between bootable primary
partitions.  When a primary partition is selected using PQ Boot, it is set
active and PQ Boot reboots the computer.

Both boot utilities are useful for different situations. For example, Boot
Manager requires an additional primary partition while PQ Boot does not. Boot
Manager allows you to choose which operating system to boot each time you
start your computer. PQ Boot, on the other hand, is ideal for users who will
only occasionally change the active partition. Boot Manager allows OS/2
installation to a logical partition and can boot OS/2 and a few other
operating systems from a logical partition. PQ Boot will only boot primary
partitions.

If both are used together, using PQ Boot to boot a partition other than Boot
Manager will deactivate Boot Manager.  To reactivate it, use PQ Boot,
PartitionMagic or some other method to set Boot Manager as the active
partition.

Boot Manager will not correctly boot from a FAT32 partition if other primary
FAT/FAT32 partitions are present. To boot a FAT32 partition, set it active
with PartitionMagic or with PQ Boot.


7. Windows NT and the PartitionCopy function
--------------------------------------------

PowerQuest's PartitionMagic does not update the Windows NT BOOT.INI file in
either the source or destination partition after a Copy operation.  Therefore
Windows NT may NOT boot from the new copy.  To make the partition bootable,
you must fix the BOOT.INI file to point to the new partition.

Also, a Copy Operation does not update drive letter references in the
destination partition Registry. You must fix some (not all) driver letter
references in the Registry.  Fixing the drive letter references is
non-trivial and we do not recommend it.


8. MagicMover from PowerQuest
-----------------------------

The UnInstaller Mover feature has been replaced by PowerQuest's MagicMover. 
MagicMover helps you move applications from one partition to another
partition. 


9. Security Problems Using Shared Drive Letters Under Windows 95
----------------------------------------------------------------

Be aware that under Windows 95, if you are using shared privileges to share
drives and you add or remove a partition (causing the drive letters to
changes), you may experience some security problems.

The following is a possible example of a security problem sharing drive
letters under Windows 95 after partitioning your hard drive.  Before you
partitioned your hard drive, your CD-ROM drive had shared privileges for say
drive D.  After you added a partition, your CD-ROM became drive E.  However,
because your CD-ROM (drive D) had shared privileges and you added a
partition, your shared privileges would still be assigned to drive D. 
Therefore, you could potentially be sharing information from your D:
partition that you do not wish to share.

To resolve this problem, you may want to check, and if necessary reset your
shared privileges in Windows 95 after you have added or removed a partition. 
You will not be affected by this situation if you share a directory and its
parent directory and its parent drive letter changes, because the shared
privilege would be lost.


10. Partition Magician Newsletter
---------------------------------

PowerQuest has a monthly electronic newsletter that is dedicated to official 
announcements regarding PartitionMagic. Signing up on the list will give you
all the information you need regarding product tips, bugs, and patches. Just
go to our home page (www.powerquest.com), enter your email address into the
space provided and hit the "Sign me up" button. You will be e-mailed a
response verifying your subscription.



 







