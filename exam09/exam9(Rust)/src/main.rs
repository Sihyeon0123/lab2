use std::io;

fn main() {
    let mut input_str = String::new();

    // 문자열로 입력받기
    println!("행렬의 크기를 입력해 주세요: ");
    io::stdin().read_line(&mut input_str).expect("입력 실패!");

    // 입력 문자열을 공백으로 분리
    let mut input_values = input_str.trim().split_whitespace();

    // 첫 번째 값 가져오기
    let x_str = input_values.next().expect("값이 없습니다.");
    
    // 두 번째 값 가져오기
    let y_str = input_values.next().expect("값이 없습니다.");

    // 정수로 변환
    let x: i32 = x_str.parse().expect("정수 변환 실패");
    let y: i32 = y_str.parse().expect("정수 변환 실패");

    println!("입력받은 숫자: x = {}, y = {}", x, y);

    let mut vec: Vec<Vec<i32>> = Vec::new();
    let mut vec2: Vec<Vec<i32>> = Vec::new();
    let mut result_vec: Vec<Vec<i32>> = Vec::new();

    // 첫번째 행려의 값 입력
    println!("첫번째 행렬의 값을 입력해 주세요:");
    for i in 0..y {
        println!("행 {}의 값을 공백으로 구분하여 입력하세요:", i + 1);
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("입력 실패");

        let row_values: Vec<i32> = input
            .split_whitespace()
            .map(|s| s.parse().expect("정수 변환 실패"))
            .collect();

        if row_values.len() != x as usize {
            println!("올바른 열 개수를 입력하지 않았습니다.");
            continue;
        }

        vec.push(row_values);
    }
    
    println!();
    println!("두번째 행렬의 값을 입력해 주세요:");
    for i in 0..y {
        println!("행 {}의 값을 공백으로 구분하여 입력하세요:", i + 1);
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("입력 실패");

        let row_values: Vec<i32> = input
            .split_whitespace()
            .map(|s| s.parse().expect("정수 변환 실패"))
            .collect();

        if row_values.len() != x as usize {
            println!("올바른 열 개수를 입력하지 않았습니다.");
            continue;
        }

        vec2.push(row_values);
    }

    println!();
    println!("결과 출력:");
    // 합 연산
    for i in 0..y {
        let mut temp: Vec<i32> = Vec::new();
        for j in 0..x{
            temp.push(vec[i as usize][j as usize] + vec2[i as usize][j as usize]);
        }
        result_vec.push(temp);
    }


    for i in 0..y {
        for j in 0..x {
            print!("{} ", result_vec[i as usize][j as usize]);
        }
        println!();
    }

}
