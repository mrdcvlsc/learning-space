## MongoDB Shell Cheat-Sheet

A concise reference for common MongoDB shell (`mongosh`) commands, structured by operation type. Copy-paste examples directly into your shell.

---

### 1. Prerequisites

- **Install MongoDB**: Download from [https://www.mongodb.com/try/download/community](https://www.mongodb.com/try/download/community)
- **Install the shell**: `mongosh` comes bundled with recent MongoDB releases

---

### 2. Starting & Exiting the Shell

```bash
mongosh        # Launch the MongoDB shell
.exit          # Exit the shell
```

---

### 3. Database Operations

| Command             | Description                               |
| ------------------- | ----------------------------------------- |
| `show dbs`          | List all databases                        |
| `use <dbName>`      | Switch to (or create) database `<dbName>` |
| `db.dropDatabase()` | Drop the currently selected database      |

---

### 4. Collection & Document CRUD

#### 4.1 Insert Documents

```js
// Single document
db.collection.insertOne({ name: "Alice", age: 30 });

// Multiple documents
db.collection.insertMany([
  { name: "Bob",   age: 25 },
  { name: "Carol", age: 28 }
]);
```

#### 4.2 Read / Query Documents

- **Basic find**

  ```js
  db.collection.find()               // All documents
  db.collection.find().limit(3)      // First 3 documents
  db.collection.find().skip(2).limit(3)
  ```

- **Sorting**

  ```js
  db.collection.find().sort({ name: 1 }).limit(3)   // Asc by name
  db.collection.find().sort({ age: -1 })            // Desc by age
  db.collection.find().sort({ age:1, name:-1 })     // Multi-field
  ```

- **Projection** (select fields)

  ```js
  db.collection.find({ name:"Alice" }, { name:1 })          // Include name + _id
  db.collection.find({ name:"Alice" }, { name:1, _id:0 })   // Only name
  db.collection.find({ name:"Alice" }, { age:0 })           // All except age
  ```

#### 4.3 Comparison & Logical Operators

| Operator                     | Example                                          | Description       |
| ---------------------------- | ------------------------------------------------ | ----------------- |
| `$eq`                        | `{ age: { $eq: 30 } }`                           | Equal             |
| `$ne`                        | `{ age: { $ne: 30 } }`                           | Not equal         |
| `$gt`, `$lt`, `$gte`, `$lte` | `{ age: { $gt:20, $lt:40 } }`                    | Range comparisons |
| `$in`, `$nin`                | `{ status: { $in:["A","B"] } }`                  | In / not in array |
| `$exists`                    | `{ field: { $exists:true } }`                    | Field existence   |
| `$and`                       | `{ $and:[ { age:{$gt:5} }, { name:"Bob" } ] }`   | Logical AND       |
| `$or`                        | `{ $or:[ { age:{$lt:20} }, { age:{$gt:30} } ] }` | Logical OR        |
| `$not`                       | `{ age: { $not:{ $gt:10 } } }`                   | Negation          |

#### 4.4 Other Query Features

```js
// Compare two fields
db.collection.find({ $expr: { $gt: ["$age","$score"] } });

// Nested fields
db.collection.find({ "address.city": "London" });

// Single result
db.collection.findOne({ age: { $lte: 40 } });

// Count
db.collection.countDocuments({ age: { $lte: 40 } });
```

---

### 5. Update Operations

| Operation  | Syntax                                       |
| ---------- | -------------------------------------------- |
| updateOne  | `db.coll.updateOne(filter, update)`          |
| updateMany | `db.coll.updateMany(filter, update)`         |
| replaceOne | `db.coll.replaceOne(filter, replacementDoc)` |

#### Update Modifiers

```js
// Set or change field value
db.coll.updateOne({ name:"Bob" }, { $set:{ age:26 } });

// Increment numeric field
db.coll.updateOne({ _id:ObjectId("…") }, { $inc:{ score:5 } });

// Rename a field
db.coll.updateOne({ _id:ObjectId("…") }, { $rename:{ oldName:"newName" } });

// Remove a field
db.coll.updateOne({ _id:ObjectId("…") }, { $unset:{ obsoleteField:"" } });

// Array operations
db.coll.updateOne({ _id:ObjectId("…") }, { $push:{ tags:"new" } });
db.coll.updateOne({ _id:ObjectId("…") }, { $pull:{ tags:"old" } });
```

---

### 6. Delete Operations

```js
// Delete one document
db.collection.deleteOne({ _id:ObjectId("…") });

// Delete multiple
db.collection.deleteMany({ status:"inactive" });
```

---

