(*Program to invert an array and
sum its even index elements.*)

PROGRAM e2;

VAR
  arr: array [0..6] of integer=(1, 2, 3, 4, 5, 6, 7);
    i, j, aux, sum: integer;

BEGIN
	i := low(arr);
	j := high(arr);
	sum := 0;

	for i := 0 to round(high(arr) / 2) do begin
		aux := arr[i];
		arr[i] := arr[j];
		arr[j] := aux;
		j -= 1
	end;

	for i := 0 to high(arr) do begin
		if ((i = 0) or (i mod 2 = 0)) then sum := sum + arr[i];
	end;

	write('Vetor invertido: [ ');
	for i:= 0 to high(arr) do write(arr[i], ' ');
	writeln(']');
	writeln('Soma dos elementos de indice par: ', sum);
END.
