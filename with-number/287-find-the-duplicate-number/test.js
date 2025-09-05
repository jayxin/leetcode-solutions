// 1^2^..^n
function xxor(n) {
  let ret = 0;
  for (let i = 1; i <= n; ++i) {
    ret ^= i;
  }
  return ret;
}

// 1^2^..^n
function xxor1(n) {
  if (n & 1) { // 奇数
    let a = (n + 1) / 2;
    if (a & 1) {
      return 1;
    } else {
      return 0;
    }
  } else { // 偶数
    let a = n / 2;
    if (a & 1) {
      return n + 1;
    } else {
      return n;
    }
  }
}

//for (let i = 1; i <= 50; ++i) {
//  //console.log(i, ": ", xxor(i));
//  console.log(i, ": ", xxor1(i));
//}

// 偶数 n:
//    n / 2 -> 偶数 -> 1^..^n -> n
//    n / 2 -> 奇数 -> 1^..^n -> n + 1
// 奇数 n:
//    (n+1)/2 -> 偶数 -> 1^..^n -> 0
//    (n+1)/2 -> 奇数 -> 1^..^n -> 1
