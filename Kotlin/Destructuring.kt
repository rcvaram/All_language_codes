data class User(val email: String, val password: String)

fun main(args: Array<String>) {
    // Using Pair
    val numbers = Pair(2, 4)
    val (first, second) = numbers

    println("First: $first, Second: $second")

    // Using Triple
    val city = Triple(0, "Budapest", "Hungary")
    val (id, cityName, country) = city

    println("City ID: $id, City name: $cityName, Country: $country")

    // Using Data Class
    val user = User("user@email.com", "HiddenPwd")
    val (email, password) = user

    println("Email: $email, Password: $password")
}