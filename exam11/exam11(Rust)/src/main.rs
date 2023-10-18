use std::collections::BTreeMap;
use std::io;

struct Student {
    mid_exam: i32,
    final_exam: i32,
}

fn main() {
    let mut student_map: BTreeMap<String, Student> = BTreeMap::new();
    println!("학생수를 입력해 주세요: ");
   
    let mut num = String::new();
    io::stdin().read_line(&mut num).expect("입력을 읽을 수 없습니다.");
    let num: i32 = num.trim().parse().expect("잘못된 숫자 형식입니다.");

    for _ in 0..num {
        let mut name = String::new();
        let mut mid_exam = String::new();
        let mut final_exam = String::new();

        println!("학생 이름: ");
        io::stdin().read_line(&mut name).expect("입력을 읽을 수 없습니다.");
        let name = name.trim().to_string();

        println!("중간 시험 점수: ");
        io::stdin().read_line(&mut mid_exam).expect("입력을 읽을 수 없습니다.");
        let mid_exam: i32 = mid_exam.trim().parse().expect("잘못된 숫자 형식입니다.");

        println!("기말 시험 점수: ");
        io::stdin().read_line(&mut final_exam).expect("입력을 읽을 수 없습니다.");
        let final_exam: i32 = final_exam.trim().parse().expect("잘못된 숫자 형식입니다.");

        println!();

        student_map.insert(name, Student { mid_exam, final_exam });
    }

    let mut name = String::new();
    println!("찾을 학생의 이름을 입력해 주세요: ");
    io::stdin().read_line(&mut name).expect("입력을 읽을 수 없습니다.");
    let name = name.trim();

    match student_map.get(name) {
        Some(student) => {
            println!("학생을 찾았습니다:");
            println!("이름: {}", name);
            println!("중간 시험 점수: {}", student.mid_exam);
            println!("기말 시험 점수: {}", student.final_exam);
        }
        None => {
            println!("학생을 찾을 수 없습니다.");
        }
    }
}
