# Search-Directory
Specyfikacja programu:
1. Do wykonania jest aplikacja (plik wykonywalny) w formie pliku programu *.EXE, skompilowany w dowolnym kompilatorze, działający pod kontrolą systemu Windows.
Plik aplikacji nazywać się winien TEST1_20170712_WS.exe. Program musi mieć własny interfejs oraz możliwość uruchamiania z linii poleceń z podanymi parametrami. Program, w ujęciu ogólnym, będzie służył do wyszukiwania (listowanie, możliwość raportu, możliwość przejścia do samego pliku) zdublowań plików znajdujących się w różnych katalogach, po całej nazwie pliku lub po wybranych zdefiniowanych częściach nazw plików, według zadanych ustawień. Program służył będzie do kontroli wyników prac tzw. indeksacji opisowej plików dokumentów.
2. Pliki będą przechowywane w złożonej strukturze katalogowej, przynajmniej o 3-poziomowym zagnieżdżeniu. Program musi dawać możliwość wskazania katalogu głównego, w którym będą znajdować się podkatalogi lub same pliki. W zadanej strukturze katalogowej będą znajdować się pliki, których nazwy będą utworzone według klucza, to znaczy, że będą składać się z przewidywalnych części, np. z kilku części oddzielonych zadanymi separatorami. W interfejsie program u należy umieścić tzw. maskę ogólną plików np. "*.PDF", która będzie służyć do wyszukiwania plików i następnie dokonywania analizy wyłącznie wśród wyszukanych plików. W interfejsie programu poza możliwością wskazania katalogu głównego i maski ogólnej plików należy umieścić kontrolki, które będą służyć do określenia definicji części nazw plików oraz separatorów z jakich składać się będą nazwy wyszukiwanych plików. Każda z części może być liczbą, literą lub kombinacją liczb i liter. Separatory muszą być znakami dopuszczalnymi w nazwach plików w systemie Windows (np. nie dopuszcza się '\').
3. Po wskazaniu katalogu głównego, określenia maski ogólnej plików, określenia definicji z czego składać się mają nazwy plików, wśród których wyszukujemy zdublowań, w interfejsie programu muszą znajdować się kontrolki służące do definicji reguł zdublowań, w tym:
a. reguła podstawowa dotycząca całych nazw plików,
b. reguły dotyczące konkretnych uprzednio określonych części np. część 2 i część 3 równe (=) oraz część 4 i część 5 różne (<>) lub np. tylko część 2 i część 3 równe (=),
d. reguły pomijania lub uwzględniania zdefiniowanych separatorów oddzielających części.
4. Program musi posiadać możliwość sprawdzenia poprawności określenia poprawności definicji reguł zdublowań w kontekście definicji części nazw plików, np. kiedy w definicji nazw plików nie występuje część 4 pliku wówczas nie można pozwolić na wyszukiwanie zdublowań po nie zdefiniowanej (nie istniejącej) części 4. Program musi także posiadać możliwość kontroli plików spełniających maskę ogólną w kontekście posiadania części i separatorów określonych w definicji części. Wyniki kontroli muszą pokazywać się na liście błędów niezależnej od listy wyników analizy zdublowań.
5. Program musi posiadać możliwość wykonania przeszukiwania poprzez wykonanie polecenia "Analizuj" (przycisk). Po tym czasie musi pokazywać się postęp wyszukiwania jeżeli wyszukiwanie ma zająć więcej niż 3 sekundy. Wyniki wyszukiwania należy umieścić na liście tak aby widać było zdublowanie sąsiadujących plików. Na liście muszą znaleźć się WYŁĄCZNIE pliki spełniające regułę zdublowania. Lista może być zorganizowana w stylu TTreeView lub TListView lub innym dostarczanym przez kompilator zapewniającym pracę na kolumnach (polach), w tym co najmniej: Lp., nazwa pliku, ścieżka do pliku pomijając katalog główny, powód umieszczenia na liście (zdublowanie).
6. Program musi mieć wkompilowane wszelkie wymagane pliki to jest nie może wymagać przy uruchomieniu dodatkowych plików.
7. Program musi mieć możliwość uruchomienia z linii poleceń z parametrami np. TEST1_20170712_WS.exe <parametr1> <parametr2> <parametr3> gdzie:
a. <parametr1> zawiera ścieżkę do katalogu głównego,
b. <parametr2> zawiera maskę ogólną plików przeznaczonych do analizy np. "*.PDF" (taką jaką używa się w systemie Windows do wyszukiwania - odpowiednik ustawienia tzw. maski ogólnej w interfejsie,
c. <parametr3> zawiera ścieżkę do pliku raportu (pliku tekstowego) zawierającego wynik wyszukiwania zdublowań.
Wyszukiwanie z linii poleceń dotyczy wyłącznie wyszukiwania zdublowań po całych nazwach plików (reguła podstawowa dotycząca całych nazw plików).
8. Poniżej zamieszczamy przykład struktury katalogów i plików do analizy:
2016
120616_2
PK-120616_2.0022 PK-120616_2.0022-R2016-Z0011-WET.P.2.2016.PDF PK-120616_2.0022-R2016-Z0011-WET.P.226.2016.PDF
PK-120616_2.0022-R2016-Z0015-WET.P.226.2016.PDF
PK-120616_2.0018
PK-120616_2.0018-R2016-Z0012-WET.P.38.2016.PDF
PK-120616_2.0018-R2016-Z0013-WET.P.39.2015.PDF
PK-120616_2.0020 PK-120616_2.0020-R2016-Z0013-WET.P.232.2016.PDF
PK-120616_2.0020-R2016-Z0015-WET.P.1826.2016.PDF
PK-120616_2.0020-R2016-Z0018-WET.P.698.2016.PDF
120616_8
PK-120616_8.0021
PK-120616_8.0021-R2016-Z0014-WET.P.51.2016.PDF
PK-120616_8.0021-R2016-Z0015-WET.P.518.2016.PDF
PK-120616_8.0019
PK-120616_8.0019-R2016-Z0015-WET.P.4.2016.PDF PK-120616_8.0019-R2016-Z0017-WET.P.687.2016.PDF PK-120616_8.0019-R2016-Z0017-WET.P.12.2016.PDF
PK-120616_8.0025 PK-120616_8.0025-R2016-Z0016-WET.P.232.2016.PDF
PK-120616_8.0025-R2016-Z0017-WET.P.9878.2016.PDF
120616_10
PK-120616_10.0001 PK-120616_10.0001-R2016-Z0017-WET.P.332.2016.PDF
PK-120616_10.0001-R2016-Z0030-WET.P.18.2016.PDF
PK-120616_10.0001-R2016-Z0018-WET.P.1889.2016.PDF PK-120616_10.0001-R2016-Z0020-WET.P.332.2016.PDF PK-120616_10.0001-R2016-Z0021-WET.P.332.16.PDF
PK-120616_10.0002 PK-120616_10.0002-R2016-Z0019-WET.P.232.16.PDF
PK-120616_10.0002-R2016-Z0020-WET.P.199.2016.PDF
Powyższy przykład zawiera następujące zdublowania, które program winien wykrywać:
Pliki zawierające identyczne części 1,2,3,4, różniące się częścią 5 przy czym w interfejsie definicji zdublowań
Pliki mające identyczną część 1,2,5 z uwzględnieniem zapisu roczników w formie 4 cyfrowej lub 2 cyfrowej (w danym katalogu)
Pliki mające identyczną tylko część 5, z uwzględnieniem zapisu roczników w formie 4 cyfrowej lub 2 cyfrowej (w różnych katalogach)
