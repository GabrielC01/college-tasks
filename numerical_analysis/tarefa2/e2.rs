use std::iter::zip;

// Função que escalona matriz aumentada.
// Parâmetros: matriz escalável (Vector).
// Retorno: Ou um vetor com as linhas ou uma mensagem de erro.
fn scale(matrix: &Vec<Vec<f32>>) -> Result<Vec<Vec<f32>>, String> {
    let result: Result<Vec<Vec<f32>>, String>;

    let mat_num_rows = matrix.len();
    let mat_num_cols = matrix[0].len();

    // Verifica se matriz é escalonável.
    if mat_num_rows == mat_num_cols - 1 {
        let mut matrix_scaled = matrix.clone();
        
        // Percorre a diagonal principal (seus índices, no caso).
        for pivot_index in 0..mat_num_rows {
            let mut temp_matrix = matrix_scaled[..pivot_index+1].to_vec();

            for row in &matrix_scaled[pivot_index+1..] {
                let m = row[pivot_index] / &matrix_scaled[pivot_index][pivot_index];
                let l = row
                    .into_iter()
                    .enumerate()
                    .map(|e| { e.1 - m * matrix_scaled[pivot_index][e.0] })
                    .collect();
                temp_matrix.push(l);
            }

            matrix_scaled = temp_matrix;
        }

        result = Ok(matrix_scaled);
    } else {
        result = Err("Matriz inviável de se escalonar.".to_string());
    }

    result
}

// Função que resolve sistemas pela eliminação gaussiana.
// Parâmetros: matriz escalonada.
// Retorno: vetor com os valores das variáveis.
fn replace_regressively(matrix: Vec<Vec<f32>>) -> Vec<f32> {
    let mut results = Vec::<f32>::new();
    let mut pivot_index = 0;

    // Ax = b
    let mut a = Vec::<Vec<f32>>::new();
    let mut b = Vec::<f32>::new();
    for row in matrix {
        a.push(row[pivot_index..row.len()-1].to_vec());
        b.push(*row.last().unwrap());
        pivot_index += 1;
    }

    let rev_a = a.iter().rev();
    let rev_b = b.iter().rev();
    for row in zip(rev_a, rev_b) {
        if row.0.len() > 1 {
            let mut summation = 0.0;
            for term in zip(&row.0[1..], results.iter().rev()) {
                summation += term.0 * term.1;
            }
            results.push((row.1 - summation) / row.0[0]);
        } else {
            results.push(row.1 / row.0[0]);
        }
    }

    results
        .into_iter()
        .rev()
        .collect()
}

fn main() {
    let matrix = vec![
        vec![3.0, 2.0, 4.0, 1.0],
        vec![1.0, 1.0, 2.0, 2.0],
        vec![4.0, 3.0, -2.0, 3.0]
    ];

    let results = replace_regressively(scale(&matrix).unwrap()); 

    for x in zip(1..results.len()+1, results) {
        println!("x{} = {:.2}", x.0, x.1);
    }
}
