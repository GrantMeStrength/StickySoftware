     REM
     REM                        GALSAT
     REM           
     REM    This is the code from which GALSAT was developed.
     REM    See Sky & Telescope June 1989 page 651
     REM    Modified for QBASIC on PC
     REM
     REM    The code is included here so that users can make their
     REM    own WINDOWS, Macintosh, etc. version.
     REM    Dan Bruton (email:wdb3926@zeus.tamu.edu)
     REM
     REM ************************* Constants *****************************
     DIM SMA(10), E(10), U(10), CS(10), T(10)
     DIM RS(10), MS(10), AV(10), N$(10), J(10), K(10), K1(10)
     PI = 3.14159265#
     P = PI / 180
     REM Screen Dimensions
     XMAX = 639: YMAX = 460
     REM Scale to fit screen (kilometers per pixel)
     SCALE = 1880000 / 170
     REM Radius of Jupiter in Kilometers
     RP = 71398
     REM Semimajor Axis of the Satellites' Orbit in Kilometers
     SMA(1) = 421600!: SMA(2) = 670900!: SMA(3) = 1070000!: SMA(4) = 1880000!
     REM Eccentricity of Satellites' Orbit
     E(1) = 0: E(2) = 0: E(3) = .001: E(4) = .01
     REM Names of the Satellites
     N$(1) = "Io": N$(2) = "Europa": N$(3) = "Ganymede": N$(4) = "Callisto"
     REM Incline Angle of Orbit with respect to Viewer in Degrees
     IA(1) = 90!: IA(2) = 90: IA(3) = 90: IA(4) = 90
     REM (Use IA(I) = 90 for top view; ~0 for Earth View)
     REM Satellites' Color
     CS(1) = 4: CS(2) = 11: CS(3) = 2: CS(4) = 3
     REM ********************* DETERMINE TIME *******************************
     REM  User enter's date here......or get date from computer.
     REM  Universal Date and Times Below
     NMONTH = 7: NDAY = 16: NYEAR = 1994
     NHOUR = 19: NMIN = 27: NSEC = 0
     JIK = 0
     REM *********************** JULIAN DAY *********************************
     JIK = JIK + 1
     GGG = 1: IF NYEAR <= 1585 THEN GGG = 0
     F = (NHOUR / 24!) + (NMIN / (24! * 60!)) - .5
     JD = -1 * INT(7 * (INT((NMONTH + 9) / 12) + NYEAR) / 4)
     S = SGN(NMONTH - 9): A = ABS(NMONTH - 9)
     J1 = INT(NYEAR + S * INT(A / 7))
     J1 = -1 * INT((INT(J1 / 100) + 1) * 3 / 4)
     JD = JD + INT(275 * NMONTH / 9) + NDAY + (GGG * J1)
     JD = JD + 1721027! + 2 * GGG + 367 * NYEAR: REM Julian Day
     REM ********************** FIND MOON ANGLES *************************
     NN = JD - 2415020! + F
     MT = (358.476 + .9856003# * NN) * P
     MJ = (225.328 + .0830853# * NN) * P
     JJ = 221.647 + .9025179# * NN
     VT = 1.92 * SIN(MT) + .02 * SIN(2 * MT)
     VJ = 5.55 * SIN(MJ) + .17 * SIN(2 * MJ)
     K = (JJ + VT - VJ) * P
     DT = SQR(28.07 - 10.406 * COS(K))
     Z = SIN(K) / DT
     II = ATN(Z / SQR(1 - Z * Z))
     II = II / P
     F = (NN - DT / 173)
     F1 = II - VJ
     U(1) = 84.5506 + 203.405863# * F + F1: REM Theta Coordinates of Orbits
     U(2) = 41.5015 + 101.2916323# * F + F1
     U(3) = 109.977 + 50.2345169# * F + F1
     U(4) = 176.3586 + 21.4879802# * F + F1
     REM ********************* Show Results ********************************
     SCREEN 12: CLS
     PRINT " NAME       X    Y   Angle   Sup.Conj.Angle"
     CIRCLE ((XMAX / 2), (YMAX / 1.65)), RP / SCALE, 12: REM  Jupiter
     PAINT ((XMAX / 2), (YMAX / 1.65)), 12, 12: REM           Jupiter
     LINE (0, 90)-(XMAX, YMAX), 15, B: REM                    Box
     FOR I = 1 TO 4
     CIRCLE (XMAX / 2, YMAX / 1.65), SMA(I) / SCALE, 8: REM   Orbital Paths
     U(I) = ((U(I) / 360) - INT(U(I) / 360)) * 360
     T(I) = U(I) * P + PI
     R = SMA(I) * (1 - (E(I) ^ 2)) / (1 + (E(I) * COS(T(I))))
     X = (XMAX / 2) + (R * SIN(T(I)) / SCALE)
     Y = (YMAX / 1.65) - INT((R * COS(T(I)) * SIN(IA(I) * P) / SCALE) + .5)
     CIRCLE (X, Y), 1, CS(I)
     UU = U(I) + 180: IF UU > 360 THEN UU = UU - 360
     PRINT USING "\      \   ###  ###   ###      ####"; N$(I); X; Y; U(I); UU
     NEXT I
     LOCATE 3, 55: PRINT "DATE :"; NMONTH; "-"; NDAY; "-"; NYEAR
     LOCATE 4, 55: PRINT "TIME :"; NHOUR; ":"; NMIN; ":"; NSEC
     LOCATE 27, 2: PRINT "Earth is straight down"
     LOCATE 28, 2: PRINT "in this polar view."
     END

