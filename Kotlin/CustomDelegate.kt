import kotlin.reflect.KProperty

// Automatically returns the value of the property as it's name
// E.g: dog will return "dog"

class AutoPropertyNaming {
    operator fun getValue(thisRef: Any?, prop: KProperty<*>): String {
        return "${prop.name}"
    }
}

fun main(args: Array<String>) {
    val dog by AutoPropertyNaming()
    val cat by AutoPropertyNaming()
    val horse by AutoPropertyNaming()

    // Will print "dog", "cat" and "horse"
    listOf(dog, cat, horse).forEach(::println)
}