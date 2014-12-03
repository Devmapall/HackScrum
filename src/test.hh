<?hh //partial
/*
$pdo = new PDO("mysql:host=localhost;dbname=scrum;","root","uUQ8h8LY");
$stmt = $pdo->query("SELECT * FROM tasks");

$vec = Vector{};
$obj = $stmt->fetchObject();
$vec[] = $obj;

var_dump($vec);
*/

$p1 = Pair{1,new stdClass()};
$p2 = Pair{2,"blub"};

$vec = Vector{$p1,$p2};

var_dump($vec);
