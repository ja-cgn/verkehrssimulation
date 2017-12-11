Zum Starten des Simulationsservers ist zumindest ein Runtimesystem
von Java 8 (JRE) erforderlich. Im CIP-Pool ist das entsprechende JDK installiert 
und der Speicherort des jar-Files bekannt. Das jar-File wird beim
Initialisieren des Servers (bInitialisiereGrafik()) automatisch gestartet.

M�chten Sie den Server zuhause einsetzen, so m�ssen Sie das jar-File in 
das Projektverzeichnis kopieren und das JRE installiert haben.

Hier gleich die L�sungen zu h�ufigen Problemen ;-) :

    1) Das JRE ist nicht installiert.
       Um dies zu erkennen, �ffnen Sie eine CMD-Eingabeaufforderung und geben dort
       java -version
       ein. Wenn dies zur Meldung "Unbekannter Befehl" f�hrt oder die Version vor 1.8 liegt:
       -> Laden Sie das JRE von http://java.sun.com/ herunter und installieren Sie es. 
       Achten Sie darauf, dass es sich um die 32Bit-Variante handelt.
       Bei einem 64-Bit-Betriebssystem m�ssen Sie diese ggf. zus�tzlich zur 64Bit-JRE installieren.
       Die 32Bit-Variante ist zum automatischen Start des Simulationsservers erforderlich.
       Sie k�nnen auch nur mit der 64Bit-Variante arbeiten. Dann m�ssen Sie den Simuserver selbst
       starten und die Fehlermeldung dazu beim Start ignorieren.
       
    2) Ihre Firewall verhindert Kommunikation mit Port 7654.
       Ihr Programm muss mit Ihrem lokalen Rechner (127.0.0.1) Kommunikation
       �ber Port 7654 aufnehmen k�nnen. Bei ersten Start des Simulationsservers muss dies
       meistens explizit erlaubt werden.

    3) Das Programm findet den jar-File nicht in Ihrem Projektverzeichnis.
       -> Kopieren Sie den jar-File dorthin (Wenn Sie das Programm aus der VS starten, ist es
       das Verzeichnis, wo auch ihre cpp- und h-Dateien liegen).
       Im CIP-Pool wird automatisch der jar-File vom Server (P:\UserGrp\PI2) gestartet.

    4) Sie benutzen die Visual Studio Version 6 oder Visual Studio 2003 / 2005 / 2008 /2010 / 2012.
       Diese Versionen werden nicht (mehr) unterst�tzt. Bitte laden Sie Visual Studio 2015 oder 2017.
       Sie erhalten dies z.B. vom MSDN AA Portal (Dreamspark, MS Imagine).

Wenn Punkt 4 das Problem noch nicht l�st, wenden Sie sich bitte an die Betreuung
(pers�nlich, per E-Mail oder Diskussionsgruppe).

    Falls die Parameter�bergabe an die DLL nicht funktioniert, achten Sie bitte darauf, dass Sie
    das Projekt im DEBUG-Modus (nicht RELEASE-Modus!) erzeugt haben.
