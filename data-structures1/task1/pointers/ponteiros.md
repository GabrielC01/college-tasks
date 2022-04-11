#### 1
O problema é que a variável temp foi declarada como ponteiro.

#### 2
Declaram os inteiros i e j, e i é inicializo com 99.
Declara-se um ponteiro p, e atribui-se-lhe o endereço
de i.
Atribui-se a j a soma do valor presente no endereço apontado
por p e 100.

#### 3
Inicializam-se inteiros a e b, com 5 e 15, respectivamente.
Declaram-se ponteiros inteiros p e q, e atribue-se-lhes os
endereços de a e b, respectivamente.
Inicializa-se o inteiro c com a soma dos valores apontados por
p e q, respectivamente.

#### 4
Declaram-se dois inteiros, i e j, inicializando-os
com 7 e 3, respectivamente.
Declaram-se dois ponteiros inteiros, p e r, sendo r um ponteiro de
duplo nível de apontamento.
Atribui-se a p o endereço de i, e a r o endereço de p.
Atribui-se a uma variável a soma do conteúdo do endereço apontando por r
e o valor de j.

#### 5
Declaram-se inteiros x, y, um ponteiro inteiro p.
Atribui-se a y o valor 0.
p recebe o endereço de y.
x recebe o valor do endereço apontado por p.
x recebe 4.
Incrementa-se o conteúdo do endereço apontado por p e, portanto,
incrementa-se y.
Decrementa-se o conteúdo de x.
Soma-se o conteúdo do endereço apontado por p (y) ao conteúdo de x.
Portando, x contém o valor 3 e y contém o valor 4.

#### 6
a) O ponteiro p está recebendo o valor armazenado em x, e não o seu
endereço. O correto seria isto:
<code>
void main() {
	int x, *p;
	x = 100;
	p = &x;
	printf("Valor de p: %d.\n", *p);
}
</code>

b) A variável temp foi declarada como ponteiro.
O correto é isto:
<code>
void troca(int *i, int *j){
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
</code>

c) O erro é que a comparação é feita entre os endereços de memória,
e não entre as palavras.
O correto é isto:
<code>
char *a, *b;
a = "Abacate";
y = "Uva";
if (a[0] < b[0])
	printf("%s vem antes de %s no dicionario\n", a, b);
else
	printf("%s vem depois de %s no dicionario\n", a, b);
return 0;
</code>

#### 7
a) Ponteiro.
b) Ponteiro.
c) Ponteiro e multiplicação.
d) Ponteiro.

#### 8
Erros de compilação.
