# Advanced OOP Piscine - Module 01 (relationships)

![](resources/intro.webp)

## About

This is the second module of the advanced piscine of OOP, it will introduce to how variables/attributes can be linked together, using specific kind of relationship.
Here is the link to the [subject](https://cdn.intra.42.fr/pdf/pdf/109506/en.subject.pdf)

## Installation && Usage

1. Clone the repository to your local machine:

   ```bash
   git clone git@github.com:Stilram19/pescine-object-module01-Relationship.git
   ```

2. Navigate to the repository's directory:

    ```bash
    cd pescine-object-module01-Relationship/ex00/
    ```

3. Compile and Run the program:

   ``` bash
   make run
   ```

## Notes:

- **Mutual Class Inclusion**:
  - When you have two classes, each wanting to include the other, it's fine if done in separate modules. 
  - However, if the classes are included in the same module, it will raise problems.
  - The solution is to implement the classes in `.cpp` files and declare both classes using forward declarations (`class ClassName;`).

- **Composition**:
  - A fundamental concept in OOP representing a "has-a" relationship, where the component object is owned by the composite object.
  - When the composite object is destroyed, the component object is also destroyed. 
  - The composite object's destructor is called first, ensuring that the composite object does not hold an invalid reference to the component object.
  - The composite object owns the component object throughout its lifetime, meaning their relationship doesn't end until the composite is destroyed, which then leads to the component's destruction as well.
  - The memory allocated for the component object is part of the memory allocated for the composite object, just like any other attribute. Since the component object may have more than one attribute, these attributes are included within the composite object. This isn't just an analogy; it's true at least memory-wise.

- **Aggregation**:
  - Another fundamental concept in OOP, also representing a "has-a" relationship, but it's about "collecting."
  - The aggregate or whole object has a collection of part objects. When you collect an object, you have it. Before collecting it, you don't have it, and afterward, you may lose it or discard it.
  - The memory allocated for the part object is independent of the memory of the aggregate object and has its own life cycle. What is part of the memory of the aggregate object is a pointer that may or may not point to a part object, which is created and constructed in separate memory.
  - The part object exists independently and can be collected or discarded at any time. Aggregation is a weaker relationship than composition.
  - Having a component object as `std::vector<PartClass *>` is the same as having an aggregation relationship between the composite object and the `PartClass` objects.

- **Association**:
  - A fundamental concept in OOP, representing a relationship that can be one-to-one, one-to-many, or many-to-many.
  - Aggregation is a special case of association, where the relationship can be one-to-one or one-to-many.


## Find Other Modules:
- [Module-00-Encapsulation](https://github.com/Stilram19/pescine-object-module00-encapsulation)
- [Module-01-Relationships](https://github.com/Stilram19/pescine-object-module01-Relationship)
- [Module-02-UML](https://github.com/Stilram19/pescine-object-module02-UML)
- [Module-03-SOLID](https://github.com/Stilram19/pescine-object-module03-SOLID)
- [Module-04-Design Patterns](https://github.com/Stilram19/pescine-object-module04-DesignPatterns)
