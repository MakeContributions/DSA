[![.NET](https://github.com/MakeContributions/DSA/actions/workflows/dotnet.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/dotnet.yml)
[![C++](https://github.com/MakeContributions/DSA/actions/workflows/cpp.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/cpp.yml)
[![Go](https://github.com/MakeContributions/DSA/actions/workflows/go.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/go.yml)
[![Node.js CI](https://github.com/MakeContributions/DSA/actions/workflows/node.js.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/node.js.yml)
[![Python](https://github.com/MakeContributions/DSA/actions/workflows/python.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/python.yml)
[![codespell](https://github.com/MakeContributions/DSA/actions/workflows/codespell.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/codespell.yml)
[![CodeQL](https://github.com/MakeContributions/DSA/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/codeql-analysis.yml)
[![Discord](https://img.shields.io/discord/863049619734790185?color=7389D8&logo=discord&logoColor=ffffff&label=&labelColor=6A7EC2)](https://discord.gg/ydWxdqbTyK)

# Data Structures and Algorithm

Data structure and Algorithm (DSA)

## Explanations

- [English](./docs/en)
- [Español](./docs/es)
- [Português](./docs/pt)
- [Turkish](./docs/tr)
- [繁體中文](./docs/zh-tw)
- [日本語](./docs/ja)

## Contribution Guidelines

### 1. Contribution Specifications

The problem being contributed must either be a simple **file** (**Eg.** [`kruskal-algorithm.cpp`](./algorithms/CPlusPlus/Graphs/kruskal-algorithm.cpp), [`linear-search.java`](./algorithms/Java/searching/linear-search.java)) or a more complex **directory** ([`palindrome/`](./algorithms/Rust/strings/palindrome)). This is a unit `problem`.

The directory tree has the following convention of `algorithms/{language}/{category}/{problem}`, where `{language}` represents the language code of the problem (**Eg.** `CPlusPlus` for C++, `CSharp` for C# etc.), `{category}` is the topic or category of the problem being contributed (**Eg.** `strings`, `sorting`, `linked-lists` etc.), and `{problem}` is a conforming name to the problem (**Eg.** `linear-search.cpp`, `palindrome`, `queue-linked-list.cpp` etc.)

A unit `problem` must conform to the following specifications:

- The name should be in lowercase. (**Eg.** `palindrome/`, `binary-search.cpp` etc.).
- Each word must be separated by a **dash** or a **hyphen** (`-`).

**If you have a problem that belongs to a new _topic_ or _category_ than one which are present:**

1. Create a new folder and an index for it inside (a readme, `README.md` file).
2. To each new index file, write the readme with your `problem` in it ([Markdown Documentation](https://guides.github.com/features/mastering-markdown/)).
3. The folder name can also only contain **lowercase characters** and **dashes** or **hyphens** (`-`) (Eg. `strings` `sorting` etc.)

#### Simple (File) Contributions

The file should conform to the `problem` specification, and the extension (**Eg.** `linear-search.java`, `kruskal-algorithm.cpp`, `count-inversions.js` etc.)

#### Project/Folder-based Contributions

The project and folder-based contributions have a bit more stricter contribution specifications.

The folder should conform to the `problem` specification, along with the following specifications

**Folder Structure**

```bash
problem-name\
| - .gitignore
| - README.md
| - Makefile       # or the specific specification/requirements/configuration file
| - src\
    | - main.ext
```

#### `README.md` Specification / Template

````markdown
# Delete the kth node from the end

Lets  K be the total nodes in the linked list.

Observation : The Nth node from the end is (K-N+1)th node from the beginning.

So the problem simplifies down to that we have to find  (K-N+1)th node from the beginning.

One way of doing it is to find the length (K) of the linked list in one pass and then in the second pass move (K-N+1) step from the beginning to reach the Nth node from the end.
To do it in one pass. Let’s take the first pointer and move N step from the beginning. Now the first pointer is (K-N+1) steps away from the last node, which is the same number of steps the second pointer require to move from the beginning to reach the Nth node from the end.

## Prerequisites

- prerequisite library or package
- [prerequisite library](https://www.example.com/link-to-official-library)

## Instructions

- instructions to run the project
- < Simple and reproducible commands to execute the project >
  ```bash
    javac circular.java
    java circular
  ```

## Test Cases & Output < if exists>

Test Case 1:
Input- 3
       1 2 3 4 5 6
Output- 1>2>3>5>6      
````

#### `.gitignore` File

```gitignore
# add all output files and build files to be excluded from git tracking
main     # executable file also must have the project name
target/  # the build file, for example for rust
```

#### Build File / Specification File / Configuration File

It can be any of the following ones

- **C/C++**: `Makefile`
- **Python**: `requirements.txt`
- **JavaScript**: `package.json` and `package-lock.json`
- **Rust**: `Cargo.toml` and `Cargo.lock`
- **Go**: `go.mod`

#### Source Code File

The source code files should either be in `src/` folder (**Eg.** `src/main.cpp` or `src/main.js`) or the root folder (**Eg.** `palindrome.go` or `App.java`) where `ext` is the file extension for the specific programming language.

Again, the source codes must conform to a valid file structure convention that the programming language enforces.

### 2. Naming Convention

The programming should keep the naming convention rule of each programming language.

### Other topic

- [First-time contribution](CONTRIBUTING.md)

## Reviewers

| Programming Language | Users                                                       |
| -------------------- | ----------------------------------------------------------- |
| C or C++             | @Arsenic-ATG, @UG-SEP, @aayushjain7, @Ashborn-SM, @Ashad001 |
| Java                 | @TawfikYasser, @aayushjain7, @mohitchakraverty              |
| C#                   | @ming-tsai, @Waqar-107                                      |
| Go                   | @ayo-ajayi                                                  |
| Python               | @Arsenic-ATG, @sridhar-5                                    |
| JavaScript           | @ming-tsai                                                  |

## Contributors

<a href="https://github.com/MakeContributions/DSA/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=MakeContributions/DSA" />
  
</a>

## Open Graph

<img src="https://opengraph.github.com/3b128f0e88464a82a37f2daefd7d594c6f41a3c22b3bf94c0c030135039b5dd7/MakeContributions/DSA" />

## License

[MIT](./LICENSE)
