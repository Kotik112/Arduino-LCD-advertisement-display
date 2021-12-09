# Arduino advertisement LCD display / Arduino LCD reklamskylt

Disclaimer: This code has only been compiled and tested on Windows OS. 
If you are running linux or any other system architecture, make sure to change makefile to "-o program.out".

Compilation:
A makefile is included in the repository. The output is a Windows executable. Just "make".
Alternatively you can compile with the DOS command:
	g++ -Wall main.cpp ad_manager.cpp company.cpp menu.cpp serial.c -o program.exe


About the program:
The program requires at least 1 arguement to run. This arguement is the COM port you are trying to connect to.
For example: program.exe COM3 COM4
where COM3 and COM4 are the respective COM to send data to.

Main menu:

#   1. Add Adversistment    #
#   2. Export Ads to Ardu   #
#   3. Save to file         #
#   4. Read from file       #
#   5. Flush file           #
#   6. Exit                 #

1 -> Will prompt you to add a new advertisement.
2 -> Send advertisements to the COM specified at compile time.
3 -> Saves all the advertisements to file.
4 -> Reads advertisement from file.
5 -> Flushes the saved file and wipes the saved ads from memory.
6 -> Exits out of the program.

//
23/11-2021
Jakob, Arman & Unn 



# Group project for "C/C++ Programmering"

1. Uppgift

    Ni har fått uppdraget att skriva mjukvaran som skall hantera reklamskyltarna
på en fotbollsmatch. Som reklamskyltar använder vi Arduinos med LCDdisplayer.
Ni skall alltså göra två program, ett som kör på en Arduino och ett som kör
på en PC, som kontrollerar en eller flera Arduinos.

    Reklamköpare skall kunna “köpa tid” på era displayer för att visa sitt budskap. 
Tiden skall sedan fördelas mellan reklamköparna i proportion till hur mycket de har
betalat. Efter en minut skall man ha visat alla budskap. Så om
“Hederlige Harrys Begangande Bilar” har betalat 5000 kr för att Visa “köp bil
hos HH” och “Ärlige Erlands Pensionsförvaltning” har betalat 5000 kr för att
visa “Pension? Ja tack!” så skall de få 50% av tiden, alltså 30s, var.
Budskapen skall man kunna mata in i runtime i ert PC-program

    Ni får själva välja vettiga gränser (kortaste tiden något kan visas, längd på
budskap osv).

1. 0. 1. Kod för serieport:

- Här finns ett lib för windows som användes i en tidigare omgång av kursen:
https://gist.github.com/aspcodenet/f46069ec95c26a260ab7b9b10b4c95d4

- Här finns en ganska bra tutorial som bör funka för GNU/Linux och Mac:
https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serialports-using-c-cpp/


2. Krav för godkänt

2. 1. Allmänna krav

- Koden skall vara uppdelad i moduler (filer) på ett genomtänkt sätt.
- Koden skall kompilera utan varningar med -Wall.
- Koden skall komma med en instruktion för hur man kompilerar och kör den.
- Det kan vara en Makefile, ett shell-skript eller bara en textfil med instruktioner.
- Dataflödena i programmet skall vara genomtänkta. Onödig minneskopiering
skall undvikas.
- Minnet skall hanteras korrekt, minne man har fått av malloc/new skall frias
med free/delete.

2. 2. Krav på lösningen

Man skall kunna ha mer än en Arduino samtidigt. 
När man startar programmet skall man ge serieportarna som argument. 
På godkäntnivå får man visa samma sak på alla Arduinos.


3. Krav för väl godkänt

- Slumpa budskapen så att alla Arduinos inte alltid visar samma sak.
- Få texten att scrolla från höger till vänster på displayen.
- Man skall kunna läsa in information om reklamköpare och deras budskap från en fil vid programstart. 
- Filen bör innehålla namn på företaget, vilket
budskap de vill visa samt hur mycket de har betalat.
