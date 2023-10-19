use std::collections::BTreeMap;
use std::io;

fn main() {
    let mut students: BTreeMap<String, BTreeMap<i32, i32>> = BTreeMap::new();
    let mut mid_score: i32;
    let mut final_score: i32;

    let mut num = String::new();
    println!("학생 수를 입력해 주세요:");
    io::stdin().read_line(&mut num).expect("입력 에러");
    let num: i32 = num.trim().parse().expect("정수를 입력하세요");

    let mut i = 1;

    while i <= num {
        println!("[{}] 학생이름과 중간, 기말고사 점수를 입력해 주세요:", i);

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("입력 에러");
        let tokens: Vec<_> = input.trim().split_whitespace().collect();

        if tokens.len() != 3 {
            println!("잘못된 입력입니다. 다시 시도하세요.");
            continue;
        }

        let name = tokens[0].to_string(); // name 변수를 제거하고 직접 사용
        mid_score = tokens[1].parse().expect("정수를 입력하세요");
        final_score = tokens[2].parse().expect("정수를 입력하세요");

        if students.contains_key(&name) {
            println!("중복된 이름이 있습니다. 다시 시도하세요.");
            continue;
        }

        let mut temp = BTreeMap::new();
        temp.insert(mid_score, final_score);
        students.insert(name, temp);

        i += 1;
    }

    println!("입력된 학생을 출력합니다:");
    for (student, scores) in &students {
        print!("{} ", student);
        for (mid, final_score) in scores {
            println!("{} {}", mid, final_score);
        }
    }

    println!("검색할 이름을 입력하세요:");
    let mut search_name = String::new();

    while io::stdin().read_line(&mut search_name).is_ok() {
        search_name = search_name.trim().to_string();

        match students.get(&search_name) {
            Some(scores) => {
                println!("검색 성공: {}", search_name);
                for (mid, final_score) in scores {
                    println!("중간시험: {}\n기말시험: {}", mid, final_score);
                }
            }
            None => {
                println!("검색 결과가 없습니다: {}", search_name);
            }
        }
        search_name.clear();
    }
}
