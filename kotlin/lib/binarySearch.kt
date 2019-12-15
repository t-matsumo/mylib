// upper bound
fun binarySearch () {
    var left = 0 // always mutch the condition
    var right = 1000000001 // always not mutch the condition
    while (right - left > 1) {
        val center = (right + left) / 2
        if (f(a, b, center) <= x) {
            left = center
        } else {
            right = center
        }
    }
}
