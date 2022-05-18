***СПбГЭТУ «ЛЭТИ»
Факультет компьютерных технологий и информатики (ФКТИ) 2022***
# Курсовые проекты по предмету алгоритмы и структуры данных.
**СОРТИРОВКА И ПОИСК ДАННЫХ**
> Разработать программу: ```ConsoleSorting```
- Имеется база данных, которая хранится в текстовом файле.(Файл создаётся самостоятельно.)
1. По ключу (выбирается самостоятельно) произвести сортировку данных **(Быстрая сортировка "quicksort")**
2. Реализовать поиск по заданному значению ключа **(Использовать случайные бинарные деревья поиска)**
3. Проанализировать время работы 1 и 2 алгоритма **(наилучшем, среднем, наихудшем случае)** (для этого рекомендуется создать несколько файлов с входными данными).
4. В пояснительной записке предоставить результат исследования.

**ЛИНЕЙНЫЕ СТРУКТУРЫ ДАННЫХ. РАЗРЕЖЕННЫЕ МАТРИЦЫ**
> Разработать программу подсчёта следующих характеристик заданного блока матрицы: ```ConsoleMatrix```
1. Сумму и произведение всех элементов.
2. Максимальный и минимальный элементы. 
3. Последовательность элементов, полученную при обходе по строкам (по столбцам).
-  Интерфейс позволяющий задать какую строку или столбец вывести в консоль.
4. Список локальных максимумов (минимумов). Локальным максимумом называется элемент, не имеющий соседей больших (меньших), чем он сам. Соседями элемента являются элементы, ближайшие по вертикали, горизонтали или диагонали (если таковые имеются).


***Подход:*** идея состоит в том, чтобы перебрать вктор векторов и проверить, является ли каждый элемент наименьшим или наибольшим среди смежных элементов. Если он наименьший, то это локальные минимумы, а если он наибольший, то это локальные максимумы. Ниже приведены шаги:
- Создайте два вектора max и min для хранения всех локальных максимумов и локальных минимумов. 
- Матрица должна иметь размер не менее 2х2. (в противном случае не анализирую)
- Проверить углы матрицы.(там в соседях 3-и элемента)
- Проверить строчки верхнею, нижнею, и столбцы правый и левый.(там в соседях 5-ь элементов)
- Оставшеюся середину (там 8-м элементов)
5. Минимум из максимальных элементов строк.
- В каждой строке матрицы выбираю наибольшее значение (сколько строк столько значений). И выбираю из полученных значений минимальный.
6. Максимум из минимальных элементов столбцов.
- В каждом столбце матрицы выбираю наименьшее значение (сколько столбцов столько и значений). Из полученных значений выбрать максимальное.
7. Список седловых точек. Седловой точкой называют элемент блока, такой, что он является наименьшим в своей строке и одновременно наибольшим в своем столбце, или, наоборот, наибольшим в своей строке и наименьшим в своем столбце.
