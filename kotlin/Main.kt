fun main() {
    val table = readLine()!!
    val hand = readLine()!!
    var a = 11
    a = 1 + 2
    val ans = if (hand.contains(table[0]) || hand.contains(table[1])) "yes" else "no"
    println(ans)
}
