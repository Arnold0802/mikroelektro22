# mikroelektro22
A téma választás során próbáltunk a meglévő dolgainkból, alkatrészekből összeállítani a feladat teljesítéséhez szükséges 
rendszert megvalósítani. Az alapot egy Arduino UNO adta, 
ehhez társult hozzá az alábbi részegységek, amiket a projekt során felhasználtunk:
-	Arduino UNO 
-	B10k analóg potenciométer
-	1 csatornás relé modul
-	Wiznet W5100 ethernet shield
-	mágneses nyitásérzékelő
-	DALLAS DS18B20
-	4 számjegyű 7 szegmenses kijelző
-	Breadboard, ellenállások, vezetékek
A feladat egyeztetése során szobatermosztát feladat megvalósítása mellett döntöttünk. 
A termosztát beállítását egy potméter segítségével valósítottuk meg amit a felhasználó tud szabályozni kézzel. 
A szoba hőmérsékletét az eszközhöz csatlakoztatott hőmérő mér. 
Ezt a két értéket a kijelzőn látjuk, jobb oldalon a kívánt hőmérséklet látható, 
a bal oldalon pedig a szoba hőmérsékletét látjuk. Az értékek felváltva jelennek meg a kijelzőn. 
Az eszközhöz raktunk kiegészítőket, ilyen például a nyitás érzékelő, ami nem engedi működtetni a fűtést, 
ha pl.: nyitva maradt ajtó vagy ablak van a házban. Ebben az esetben a relé nem kap áramot, 
hiába magasabb a cél hőfok a jelenleginél. A relé működését egy visszajelző led segítségével látjuk, 
hogy be van-e kapcsolva vagy sem. Ez később lehet cserélni 230V-os ra amivel lehet kapcsolni fűtőtestet.
Ami tovább okosítja a rendszert, hogy adatbázisba tároljuk a beállított és 
az adott helységben elhelyezett termosztát által mért értéket. Ebből lehetőségünk van kimutatás készíteni, 
akár grafikonra kirajzolva látjuk, hogy változik az érték. Emellett rögzíti a fűtés mennyi időt működött, 
mikor lett bekapcsolva és mikor kapcsolt ki ha elérte a kívánt hőmérsékletet vagy a felhasználó kikapcsolta azt.  
