
This is a tiny Qt based library for generating animated WebP files.

It uses CMake and is meant to be included as a subproject.

## Usage

1. Add it as a git submodule to your project
2. Include it in CMakeLists.txt like this:
```cmake
add_subdirectory(AnimatedWebP)

add_executable(MyAPP main.cpp)
target_link_libraries(MyApp PRIVATE AnimatedWebP)
```

3. Use it in code:
```c++

#include <webp_generator.hpp>

int main()
{
    ...

    WebPGenerator webpgenerator;
    webpgenerator.setDelay(std::chrono::milliseconds(100));
    webpgenerator.setLoopDelay(std::chrono::milliseconds(1000));
    webpgenerator.append(QImage("frame1.png"));
    webpgenerator.append(QImage("frame2.png"));
    webpgenerator.append(QImage("frame3.png"));
    webpgenerator.append(QImage("frame4.png"));
    webpgenerator.append(QImage("frame5.png"));

    const auto data = webpgenerator.save();

    QFile outputFile("animation.webp");
    outputFile.open(QFile::WriteOnly);
    outputFile.write(outputData);

    ...

    return 0;
```
