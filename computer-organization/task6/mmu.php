<?php
// Programa para simular gerenciamento
// de memoria.

define('MEM_SIZE', array_fill(0, 16, 0));

// Unidade de Gerenciamento de Memoria
function mmu($mode, $mar = null, $mbr = null) {
	// RAM estatica e nao global
	//static $ram = SplFixedArray(MEM_SIZE);
	static $ram = MEM_SIZE;

	// Modo de leitura
	if ($mode == 0) {
		try {
			return $ram[$mar];
		} catch (OutOfBoundsException $error) {
			return $error;
		}
	}
	
	// Modo de escrita
	if ($mode == 1) {
		try {
			$ram[$mar] = $mbr;
			return true;
		} catch (OutOfBoundsException $error) {
			return $error;
		}
	}

	// Retorna o pente
	if ($mode == 2) return implode(' ', $ram);
}

/* Uso */
// Escrita de dados
mmu(1, 0, 10);
mmu(1, 10, 'hi');

// Leitura de dados
echo mmu(0, 0) . PHP_EOL;
echo mmu(0, 10) . PHP_EOL;

// Mostra o pente todo
echo '[ ' . mmu(2) . ' ]' . PHP_EOL;
