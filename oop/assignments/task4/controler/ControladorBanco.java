package controler;

import repository.cliente.RepositorioCliente;
import repository.cliente.CPFJaCadastradoException;
import repository.cliente.ClienteNaoCadastradoException;
import model.cliente.Cliente;
import repository.conta.ContaNaoCadastradaException;
import repository.conta.ContaJaCadastradaException;
import repository.conta.RepositorioConta;
import model.conta.Conta;
import model.conta.SaldoInsuficienteException;
import java.util.List;
import repository.cliente.RepositorioClienteLista;
import repository.conta.RepositorioContaLista;

public class ControladorBanco {
    
    private RepositorioCliente repositorioCliente;
    private RepositorioConta repositorioConta;

    public ControladorBanco() {
        repositorioCliente = new RepositorioClienteLista();
        repositorioConta = new RepositorioContaLista();
    }

    public void inserirCliente(Cliente cliente) throws CPFJaCadastradoException {
        repositorioCliente.inserirCliente(cliente);
    }
    
    public void alterarCliente(Cliente cliente) throws ClienteNaoCadastradoException {
        repositorioCliente.alterarCliente(cliente);
    }
    
    public Cliente buscarCliente(String cpf) throws ClienteNaoCadastradoException {
        return repositorioCliente.buscarCliente(cpf);
    }
    
    public void excluirCliente(Cliente cliente) throws ControladorException, ClienteNaoCadastradoException {
    	// Busca listas de contas do Cliente
    	List<Conta> contasCliente = this.getAllContas(cliente.getCpf());
    	
        if (contasCliente.isEmpty()) {
            repositorioCliente.deletarCliente(cliente);
        } else {
            throw new ControladorException("Cliente com contas ativas não pode ser excluído");
        }
    }
    
    public List<Cliente> getAllClientes() {
        return repositorioCliente.getAll();
    }
    
    public Conta inserirConta(Conta conta) throws ContaJaCadastradaException {
        return repositorioConta.inserirConta(conta);
    }

    public Conta buscarConta(String numero) throws ContaNaoCadastradaException  {
        return repositorioConta.buscarConta(numero);
    }

    
    // TODO Regra de Negocio: não excluir conta com saldo
    public boolean excluirConta(Conta conta) throws ContaNaoCadastradaException {
      if (conta.getSaldo() == 0) {
        repositorioConta.deletarConta(conta);
        return true;
      }
      return false;
    }
    
    public void deposito(String numero, double valor) throws ContaNaoCadastradaException {
        Conta conta = repositorioConta.buscarConta(numero);
        conta.depositar(valor);
        repositorioConta.alterarConta(conta);
    }

    public void saque(String numero, double valor) throws ContaNaoCadastradaException, SaldoInsuficienteException {
        Conta conta = repositorioConta.buscarConta(numero);
        conta.sacar(valor);
        repositorioConta.alterarConta(conta);
    }

    public void tranferir(String origem, String destino, double valor) throws ContaNaoCadastradaException, SaldoInsuficienteException {
        Conta conta1 = repositorioConta.buscarConta(origem);
        Conta conta2 = repositorioConta.buscarConta(destino);
        conta1.sacar(valor);
        conta2.depositar(valor);
        repositorioConta.alterarConta(conta1);
        repositorioConta.alterarConta(conta2);
    }
    
    public List<Conta> getAllContas() {
        return repositorioConta.getAll();
    }

    public List<Conta> getAllContas(String cpf) {
        return repositorioConta.getAll(cpf);
    }

    public void exit() {
        // Nada para fazer
    }

}
