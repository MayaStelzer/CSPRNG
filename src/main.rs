use rand::rngs::OsRng;
use rand::RngCore; 

fn csprng_bitstring(nbits: usize) -> String {
    if nbits == 0 {
        return String::new();
    }
    let nbytes = (nbits + 7) / 8;
    let mut buf = vec![0u8; nbytes];

    OsRng.fill_bytes(&mut buf);

    buf.iter()
        .flat_map(|byte| (0..8).rev().map(move |i| (byte >> i) & 1))
        .take(nbits)
        .map(|b| char::from(b'0' + b))
        .collect()
}

fn csprng_bytestring(nbytes: usize) -> String {
    if nbytes == 0 {
        return String::new();
    }
    let mut buf = vec![0u8; nbytes];
    OsRng.fill_bytes(&mut buf); // <- same fix here

    buf.iter()
        .flat_map(|byte| (0..8).rev().map(move |i| (byte >> i) & 1))
        .map(|b| char::from(b'0' + b))
        .collect()
}

fn main() {
    println!("10-bit: {}", csprng_bitstring(10));
    println!("128-bit: {}", csprng_bitstring(128));

    println!("8-byte: {}", csprng_bytestring(8));
    println!("16-byte: {}", csprng_bytestring(16));
}
