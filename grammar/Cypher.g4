/*
 * BACH Cypher Grammar
 * Simplified Cypher query language for BACH graph database
 * Compatible with ANTLR4 4.7.2
 */

grammar Cypher;

// ============================================================================
// Parser Rules
// ============================================================================

cypher
    : SP? query EOF
    ;

query
    : singleQuery
    ;

singleQuery
    : singlePartQuery
    ;

singlePartQuery
    : (readingClause SP?)* returnClause
    | (readingClause SP?)* updatingClause (SP? updatingClause)* (SP? returnClause)?
    ;

// Reading clauses
readingClause
    : matchClause
    ;

matchClause
    : MATCH SP? pattern (SP? whereClause)?
    ;

// Updating clauses
updatingClause
    : createClause
    | deleteClause
    | setClause
    ;

createClause
    : CREATE SP? pattern
    ;

deleteClause
    : DETACH? DELETE SP? expression (SP? COMMA SP? expression)*
    ;

setClause
    : SET SP? setItem (SP? COMMA SP? setItem)*
    ;

setItem
    : propertyExpression SP? EQUAL SP? expression
    | variable SP? EQUAL SP? expression
    | variable SP? nodeLabels
    ;

// Return clause
returnClause
    : RETURN (SP? DISTINCT)? SP returnBody
    ;

returnBody
    : returnItems (SP? order)? (SP? skip)? (SP? limit)?
    ;

returnItems
    : '*'
    | returnItem (SP? COMMA SP? returnItem)*
    ;

returnItem
    : expression (SP? AS SP? variable)?
    ;

// WHERE clause
whereClause
    : WHERE SP? expression
    ;

// ORDER BY, SKIP, LIMIT
order
    : ORDER SP BY SP sortItem (SP? COMMA SP? sortItem)*
    ;

sortItem
    : expression (SP? ASC | SP? DESC)?
    ;

skip
    : SKIP SP? expression
    ;

limit
    : LIMIT SP? expression
    ;

// Pattern matching
pattern
    : patternPart (SP? COMMA SP? patternPart)*
    ;

patternPart
    : variable SP? EQUAL SP? anonymousPatternPart
    | anonymousPatternPart
    ;

anonymousPatternPart
    : patternElement
    ;

patternElement
    : nodePattern (SP? patternElementChain)*
    ;

patternElementChain
    : relationshipPattern SP? nodePattern
    ;

// Node pattern: (variable:Label {prop: value})
nodePattern
    : LPAREN SP? variable? SP? nodeLabels? SP? properties? SP? RPAREN
    ;

// Relationship pattern: -[variable:Type {prop}]->
relationshipPattern
    : DASH SP? relationshipDetail? SP? DASH SP? arrowHead
    | arrowHead SP? DASH SP? relationshipDetail? SP? DASH
    | DASH SP? relationshipDetail? SP? DASH
    ;

arrowHead
    : LT MINUS GT
    | MINUS GT
    ;

relationshipDetail
    : LBRACK SP? variable? SP? relationshipTypes? SP? properties? SP? RBRACK
    ;

// Properties: {key: value, ...}
properties
    : mapLiteral
    ;

nodeLabels
    : nodeLabel+
    ;

nodeLabel
    : COLON SP? labelName
    ;

relationshipTypes
    : COLON SP? relTypeName (SP? PIPE SP? COLON? SP? relTypeName)*
    ;

// Expressions
expression
    : orExpression
    ;

orExpression
    : xorExpression (SP? OR SP? xorExpression)*
    ;

xorExpression
    : andExpression (SP? XOR SP? andExpression)*
    ;

andExpression
    : notExpression (SP? AND SP? notExpression)*
    ;

notExpression
    : (NOT SP?)* comparisonExpression
    ;

comparisonExpression
    : addOrSubtractExpression (SP? partialComparisonExpression)*
    ;

partialComparisonExpression
    : EQUAL SP? addOrSubtractExpression
    | NEQ SP? addOrSubtractExpression
    | LT SP? addOrSubtractExpression
    | GT SP? addOrSubtractExpression
    | LTE SP? addOrSubtractExpression
    | GTE SP? addOrSubtractExpression
    ;

addOrSubtractExpression
    : multiplyDivideModuloExpression ((SP? PLUS SP? multiplyDivideModuloExpression) | (SP? MINUS SP? multiplyDivideModuloExpression))*
    ;

multiplyDivideModuloExpression
    : powerOfExpression ((SP? STAR SP? powerOfExpression) | (SP? SLASH SP? powerOfExpression) | (SP? PERCENT SP? powerOfExpression))*
    ;

powerOfExpression
    : unaryAddOrSubtractExpression (SP? CARET SP? unaryAddOrSubtractExpression)*
    ;

unaryAddOrSubtractExpression
    : (PLUS | MINUS)* atom
    ;

atom
    : literal
    | parameter
    | functionInvocation
    | variable
    | LPAREN SP? expression SP? RPAREN
    ;

functionInvocation
    : functionName SP? LPAREN SP? (DISTINCT SP?)? (expression (SP? COMMA SP? expression)*)? SP? RPAREN
    ;

functionName
    : symbolicName
    ;

propertyExpression
    : atom (SP? DOT SP? propertyKeyName)+
    ;

propertyKeyName
    : schemaName
    ;

labelName
    : schemaName
    ;

relTypeName
    : schemaName
    ;

schemaName
    : symbolicName
    ;

variable
    : symbolicName
    ;

symbolicName
    : unescapedSymbolicName
    | escapedSymbolicName
    ;

unescapedSymbolicName
    : IDENTIFIER
    ;

escapedSymbolicName
    : BACKTICK (~BACKTICK | BACKTICK BACKTICK)* BACKTICK
    ;

// Literals
literal
    : numberLiteral
    | stringLiteral
    | booleanLiteral
    | NULL_
    | mapLiteral
    | listLiteral
    ;

numberLiteral
    : DOUBLE_LITERAL
    | INTEGER_LITERAL
    ;

stringLiteral
    : STRING
    ;

booleanLiteral
    : TRUE_
    | FALSE_
    ;

mapLiteral
    : LBRACE SP? (propertyKeyName SP? COLON SP? expression (SP? COMMA SP? propertyKeyName SP? COLON SP? expression)*)? SP? RBRACE
    ;

listLiteral
    : LBRACK SP? (expression (SP? COMMA SP? expression)*)? SP? RBRACK
    ;

parameter
    : DOLLAR symbolicName
    ;

// ============================================================================
// Lexer Rules
// ============================================================================

// Keywords (case-insensitive)
MATCH: [Mm] [Aa] [Tt] [Cc] [Hh];
CREATE: [Cc] [Rr] [Ee] [Aa] [Tt] [Ee];
DELETE: [Dd] [Ee] [Ll] [Ee] [Tt] [Ee];
SET: [Ss] [Ee] [Tt];
RETURN: [Rr] [Ee] [Tt] [Uu] [Rr] [Nn];
WHERE: [Ww] [Hh] [Ee] [Rr] [Ee];
AND: [Aa] [Nn] [Dd];
OR: [Oo] [Rr];
XOR: [Xx] [Oo] [Rr];
NOT: [Nn] [Oo] [Tt];
DISTINCT: [Dd] [Ii] [Ss] [Tt] [Ii] [Nn] [Cc] [Tt];
LIMIT: [Ll] [Ii] [Mm] [Ii] [Tt];
SKIP: [Ss] [Kk] [Ii] [Pp];
ORDER: [Oo] [Rr] [Dd] [Ee];
BY: [Bb] [Yy];
ASC: [Aa] [Ss] [Cc];
DESC: [Dd] [Ee] [Ss] [Cc];
NULL_: [Nn] [Uu] [Ll] [Ll];
TRUE_: [Tt] [Rr] [Uu] [Ee];
FALSE_: [Ff] [Aa] [Ll] [Ss] [Ee];
IN: [Ii] [Nn];
IS: [Ii] [Ss];
AS: [Aa] [Ss];
DETACH: [Dd] [Ee] [Tt] [Aa] [Cc] [Hh];

// Operators
EQUAL: '=';
NEQ: '<>';
LT: '<';
GT: '>';
LTE: '<=';
GTE: '>=';
PLUS: '+';
MINUS: '-';
SLASH: '/';
PERCENT: '%';
CARET: '^';
PIPE: '|';
AMP: '&';

// Symbols
DOT: '.';
DASH: '-';
COMMA: ',';
COLON: ':';
SEMI: ';';
DOLLAR: '$';
QUESTION: '?';
AT: '@';
TILDE: '~';
BANG: '!';

// Brackets
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';

BACKTICK: '`';

// Literals
STRING: '\'' (~'\'' | '\'\'')* '\''
      | '"' (~'"' | '\\"')* '"'
      ;

INTEGER_LITERAL: DIGIT+
               | '0' [xX] HEX_DIGIT+
               ;

DOUBLE_LITERAL: DIGIT+ '.' DIGIT* EXP?
               | '.' DIGIT+ EXP?
               | DIGIT+ EXP
               ;

fragment
EXP: [Ee] [+-]? DIGIT+;

fragment
DIGIT: [0-9];

fragment
HEX_DIGIT: [0-9a-fA-F];

IDENTIFIER: [a-zA-Z_] [a-zA-Z0-9_]*;

// Whitespace
SP: [ \t\r\n]+ -> skip;

// Comments
LINE_COMMENT: '//' ~[\r\n]* -> skip;
BLOCK_COMMENT: '/*' .*? '*/' -> skip;
