Sakk program, Tehetséggondozó Programozás Alapjai kurzusra készítve.
Készítette egyénileg: Nahimi Selim Krisztián, AC1I98

A program összeállítása:
	- CMake által működik.
	- a "build.sh" bash scripttel a megfelelő cmake és make parancsok lefutnak, és létrejön egy "build" mappa. Ezen belül lesznek a futtathatók bináris fájlok.

A főprogram futtatása:
	- A főprogram egyszerűen a "main.out" futtatásával érhető el.

Bináris fájlok:
	"main.out": főprogram, amellyel játszható a játék.
		- Először a 2 játékos nevét kéri be
		- Lépések: hasonló, mint a sakknál: pl.: "b1c3"
		- Egyéb lépések:
			- "undo": visszavonás, egészen a kezdetig
			- "end": játék félbeszakítása, kilépés

	"test.out": library teszteléshez tartozó program.
		- Parancssori argumentumokként kéri be a lépéseket (szóközökkel elválasztva), ezeket lefuttatja, majd standard outputra kiírja a jelenlegi lépés számát és a sakktábla állását.

	"lib/libchess.so": Dinamikus library, melyet külsőleg is lehet használni.
		- Sajnos nem készült hozzá megfelelő header interface.


Tesztelés menete:
	- A build mappában lefuttatjuk a "make test" parancsot

	(Működése: A cmake szkript előkészített nekünk teszteket az "src/tests/" mappából beolvasva. Ebbe a mappába előre megírt "*.in" fájlok parancssori argumentumokat tartalmaznak, melyeket átad a "test.out" programnak, a kimenetét összehasonlítja egy előre megírt "*.exp" fájllal, és ha azonos a kimenet, a teszt sikeres, ha nem, elbukik.)
