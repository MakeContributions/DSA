[![.NET](https://github.com/MakeContributions/DSA/actions/workflows/dotnet.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/dotnet.yml)
[![C++](https://github.com/MakeContributions/DSA/actions/workflows/cpp.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/cpp.yml)
[![Go](https://github.com/MakeContributions/DSA/actions/workflows/go.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/go.yml)
[![Node.js CI](https://github.com/MakeContributions/DSA/actions/workflows/node.js.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/node.js.yml)
[![Python](https://github.com/MakeContributions/DSA/actions/workflows/python.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/python.yml)
[![codespell](https://github.com/MakeContributions/DSA/actions/workflows/codespell.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/codespell.yml)
[![CodeQL](https://github.com/MakeContributions/DSA/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/MakeContributions/DSA/actions/workflows/codeql-analysis.yml)
[![Discord](https://img.shields.io/discord/863049619734790185?color=7389D8&logo=discord&logoColor=ffffff&label=&labelColor=6A7EC2)](https://discord.gg/ydWxdqbTyK)

<div dir=rtl>

# هياكل البيانات و الخوارزمية

اسم المستودع يأتي من اللغة الإنجليزية Data structure and algorithm (DSA).

## الشرح

- [الإنجليزية](./docs/en)
- [الإسبانية](./docs/es)
- [البرتغاالية](./docs/pt)
- [التركية](./docs/tr)
- [الصينية التقليدية](./docs/zh-tw)
- [اليابانية](./docs/ja)

## إرشادات المساهمة

### 1. مواصفات المساهمة

المسألة التي يتم المساهمة فيها يجب ان تكون إما **ملف** بسيط كمثال ([`kruskal-algorithm.cpp`](./algorithms/CPlusPlus/Graphs/kruskal-algorithm.cpp), [`linear-search.java`](./algorithms/Java/searching/linear-search.java)) أو مجلد أكثر تعقيدًا مثل ([`palindrome/`](./algorithms/Rust/strings/palindrome)). هذا يسمى بوحدة `مسألة`. 

شجرة الدليل لديها التقليد الآتي `algorithms/{language}/{category}/{problem}`, حيث `{language}` تمثل لغة البرمجة المستخدمة لحل المسألة مثل  ( `CPlusPlus` -> C++, `CSharp` -> C# ), `{category}` هي الموضوع أو الفئة الخاصة  بالمسألة التي يتم المساهمة فيها مثل ( `strings`, `sorting`, `linked-lists` ), و `{problem}` عبارة عن اسم ملائم للمسألة مثل ( `linear-search.cpp`, `palindrome`, `queue-linked-list.cpp` ) 

أي وحدة `مسألة` يجب أن تتبع المواصفات الآتية:

- الاسم يجب أن يكون بالأحرف الأنجليزية الصغيرة مثل ( `palindrome/`, `binary-search.cpp` ).
- كل كلمة يجب أن يتم فصلها باستخدام **واصلة** (-).

**If you have a problem that belongs to a new _topic_ or _category_ than one which are present:**

**إذا كان لديك مشكلة تنتمي إلى موضوع أو فئة جديدة عن المواضيع الموجودة:**

1. اصنع مجلد جديد و فهرس له بداخله (ملف README.med).
2. لكل ملف فهرس, اكتب الreadme بالمسألة الخاصة بك فيه([Markdown Documentation](https://guides.github.com/features/mastering-markdown/)).
3. اسم المجلد يمكن أيضًا أن يتضمن **أحرف إنجليزية صغيرة** و **واصلة** (-) (Eg. `strings` `sorting` etc.).

#### مساهمات (الملف) البسيطة

الملف يجب أن يتوافق مع مواصفات `المسألة` و الملحقات مثل ( `linear-search.java`, `kruskal-algorithm.cpp`, `count-inversions.js` ).

#### مساهمات قائمة على مشروع/مجلد

المساهمات القائمة على المشروع و المجلد لديها مواصفات أكثر صرامة.

المجلد يجب أن يتوافق مع مواصفات `المسألة`, جنبًا إلى جنب مع المواصفات الآتية

**هيكل المجلد**

```bash
اسم-المسألة\
| - .gitignore
| - README.md
| - Makefile       # أو المواصفات/الاحتياجات/ملف التكوين المحددة
| - src\
    | - main.ext
```

#### مواصفات / نموذج `README.md` 

````markdown
# <عنوان المسألة>

< وصف المسألة >

## المتطلبات المسبقة

- المكتبة أو الحزمة البرمجية المتطلبة
- [المكتبة البرمجية المتطلبة](https://www.example.com/link-to-official-library)

## التعليمات

- تعليمات لتشغيل المشروع
- < أوامر بسيطة و قابلة للتكرار لتنفيذ المشروع >
  ```bash
   make # or 'cargo run', or 'dotnet run' or 'mvn exec:java' etc.
  ```

## حالات الاختبار و النتائج <إن توفرت>

<إذا كنت قادرًا على تقديم حالات اختبار، فصفها هنا، وإلا قم بإزالة هذا القسم>
````

####  ملف `.gitignore`

```gitignore
# قم بإضافة جميع ملفات الإخراج و البناء للاستبعاد من تتبع git.
main     # يجب أن يحمل ملف التنفيذ أيضًا اسم المشروع
target/  # ملف البناء على سبيل المثال في Rust.
```

#### ملف البناء / ملف المواصفات التكوين 

يمكن أن يكون أيًا من الملفات الآتية
- **C/C++**: `Makefile`
- **Python**: `requirements.txt`
- **JavaScript**: `package.json` and `package-lock.json`
- **Rust**: `Cargo.toml` and `Cargo.lock`
- **Go**: `go.mod`

#### ملف النص البرمجي المصدري (source code)

يجب أن تكون ملفات النص البرمجي المصدري إما في `src/` ( `src/main.cpp` أو `src/main.js`) أو في المجلد الجذري(root) مثل ( `palindrome.go` or `App.java`) حيث `ext` هو امتداد الملف المحدد للغة البرمجة.

مجددًا, يجب أن تتوافق ملفات النص البرمجي مع تقليد هيكل الملف الصحيح الذي تفرضه لغة البرمجة.

### 2. قواعد و تقليدات التسمية للبرمجة

يجب أن تلتزم البرمجة بقواعد و تقليدات التسمية الخاصة بلغة البرمجة المستخدمة. 

### موضوع آخر

- [First-time contribution](CONTRIBUTING.md)

## المراجعين

| المستخدمين | لغة البرمجة                                                     |
| -------------------- | ----------------------------------------------------------- |
| @Arsenic-ATG, @UG-SEP, @aayushjain7, @Ashborn-SM, @Ashad001 | C or C++             |
| @TawfikYasser, @aayushjain7, @mohitchakraverty              | Java                 |
| @ming-tsai, @Waqar-107                                      | C#                   |
| @ayo-ajayi                                                  | Go                   |
| @Arsenic-ATG, @sridhar-5                                    | Python               |
| @ming-tsai                                                  | JavaScript           |

## المساهمين

<a href="https://github.com/MakeContributions/DSA/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=MakeContributions/DSA" />
</a>

## الرسم البياني المفتوح(Open Graph)

<img src="https://opengraph.github.com/3b128f0e88464a82a37f2daefd7d594c6f41a3c22b3bf94c0c030135039b5dd7/MakeContributions/DSA" />

## الرخصة

[MIT](./LICENSE)

</div>