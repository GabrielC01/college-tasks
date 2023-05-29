// Método de Gauss-Seidel.
fn gauss_jacobi(matrix: &Vec<Vec<f32>>, b: &Vec<f32>, x0: &Vec<f32>, e: f32) -> Vec<f32> {
    let mut dr = 1.0;
    let mut x = x0.clone();
    let mut x_prev = x0.clone();

    while dr > e {
        let mut d = Vec::<f32>::new();
        x_prev = x.clone();
        for i in 0..b.len() {
            let mut sum = 0.0;
            for j in 0..matrix[i].len() {
                if j != i && j > i {
                    sum += matrix[i][j] * x_prev[j];
                } else if j != i && j < i {
                    sum += matrix[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / matrix[i][i];
            d.push(f32::abs(x[i] - x_prev[i]));
        }
        let max_d = d
            .into_iter()
            .reduce(f32::max)
            .unwrap();
        let max_x = x
            .clone()
            .into_iter()
            .reduce(f32::max)
            .unwrap();
        dr = max_d / max_x;
        println!("{:?}", x);
    }

    x
}
fn main() {
    let a = vec![
        vec![10.0, 2.0, 1.0],
        vec![1.0, 5.0, 1.0],
        vec![2.0, 3.0, 10.0],
    ];
    let b = vec![1.0, -8.0, 6.0];
    let x0 = vec![0.7, -1.6, 0.6];
    let e = 0.05;
    gauss_jacobi(&a, &b, &x0, e);
}
