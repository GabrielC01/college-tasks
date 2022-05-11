<?php
/*  
    Programa para simular gerenciamento
    de memoria.
*/

/* Tamanho da memoria (16KiB) */
define('MEM_SIZE', 16);

/* Memoria DRAM */
class DRam {
	private $dram;

	function __construct() {
		$this->dram = new SplFixedArray(MEM_SIZE);
		$this->dram = array_fill(0, count($this->dram), 0);
	}

	// Leitura de dado
	function read($mar) {
		try {
			return $this->dram[$mar];
		} catch (OutOfBoundsException $error) {
			return $error;
		}
	}

	// Escrita de dado
	function write($mar, $mbr=null) {
		try {
			$this->dram[$mar] = $mbr;
		} catch (OutOfBoundsException $error) {
			return $error;
		}
	}

	// "Visao" geral da memoria
	function get_dram() {
		return $this->dram;
	}
}

/* Excecao para insuficiente de memoria */
class NoAvailableMemoryException extends Exception {}

/* Unidade de Gerenciamento de Memoria */
class MemoryManagementUnit {
	private $dram;
	function __construct() {
		$this->dram = new DRam();
	}

	// Escrita de dado
	function write($mbr = null) {
		// Busca endereco disponivel
		$mar = array_search(0, $this->dram->get_dram());

		if ($mar === false) throw new NoAvailableMemoryException();
		else  $this->dram->write($mar, $mbr);
	}

	// Leitura da memoria toda
	function read() {
		return implode(' ', $this->dram->get_dram());
	}
}

/* Subprograma principal */
function main() {
	$mmu = new MemoryManagementUnit();
	
	// Escrita de algumas coisas
	$mmu->write(10);
	$mmu->write(10);	
	$mmu->write(50);	

	// Leitura da memoria
	echo $mmu->read() . PHP_EOL;
}

main();

// EOF

