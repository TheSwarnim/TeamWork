impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let is_vowel = |b: u8| matches!(b, b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U');
        let mut vb = s.into_bytes();
        let (mut i, mut j) = (0, vb.len() - 1);
        while i < j {
            while i < j && !is_vowel(vb[i]) {
                i += 1;
            }
            while i < j && !is_vowel(vb[j]) {
                j -= 1;
            }
            if i < j {
                vb.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        String::from_utf8(vb).unwrap()
    }
}