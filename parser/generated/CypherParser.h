
// Generated from ./Cypher.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"


namespace parser {


class  CypherParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, MATCH = 2, CREATE = 3, DELETE = 4, SET = 5, RETURN = 6, WHERE = 7, 
    AND = 8, OR = 9, XOR = 10, NOT = 11, DISTINCT = 12, LIMIT = 13, SKIP = 14, 
    ORDER = 15, BY = 16, ASC = 17, DESC = 18, NULL_ = 19, TRUE_ = 20, FALSE_ = 21, 
    IN = 22, IS = 23, AS = 24, DETACH = 25, EQUAL = 26, NEQ = 27, LT = 28, 
    GT = 29, LTE = 30, GTE = 31, PLUS = 32, MINUS = 33, SLASH = 34, PERCENT = 35, 
    CARET = 36, PIPE = 37, AMP = 38, DOT = 39, DASH = 40, COMMA = 41, COLON = 42, 
    SEMI = 43, DOLLAR = 44, QUESTION = 45, AT = 46, TILDE = 47, BANG = 48, 
    LPAREN = 49, RPAREN = 50, LBRACE = 51, RBRACE = 52, LBRACK = 53, RBRACK = 54, 
    BACKTICK = 55, STRING = 56, INTEGER_LITERAL = 57, DOUBLE_LITERAL = 58, 
    IDENTIFIER = 59, SP = 60, LINE_COMMENT = 61, BLOCK_COMMENT = 62, STAR = 63
  };

  enum {
    RuleCypher = 0, RuleQuery = 1, RuleSingleQuery = 2, RuleSinglePartQuery = 3, 
    RuleReadingClause = 4, RuleMatchClause = 5, RuleUpdatingClause = 6, 
    RuleCreateClause = 7, RuleDeleteClause = 8, RuleSetClause = 9, RuleSetItem = 10, 
    RuleReturnClause = 11, RuleReturnBody = 12, RuleReturnItems = 13, RuleReturnItem = 14, 
    RuleWhereClause = 15, RuleOrder = 16, RuleSortItem = 17, RuleSkip = 18, 
    RuleLimit = 19, RulePattern = 20, RulePatternPart = 21, RuleAnonymousPatternPart = 22, 
    RulePatternElement = 23, RulePatternElementChain = 24, RuleNodePattern = 25, 
    RuleRelationshipPattern = 26, RuleArrowHead = 27, RuleRelationshipDetail = 28, 
    RuleProperties = 29, RuleNodeLabels = 30, RuleNodeLabel = 31, RuleRelationshipTypes = 32, 
    RuleExpression = 33, RuleOrExpression = 34, RuleXorExpression = 35, 
    RuleAndExpression = 36, RuleNotExpression = 37, RuleComparisonExpression = 38, 
    RulePartialComparisonExpression = 39, RuleAddOrSubtractExpression = 40, 
    RuleMultiplyDivideModuloExpression = 41, RulePowerOfExpression = 42, 
    RuleUnaryAddOrSubtractExpression = 43, RuleAtom = 44, RuleFunctionInvocation = 45, 
    RuleFunctionName = 46, RulePropertyExpression = 47, RulePropertyKeyName = 48, 
    RuleLabelName = 49, RuleRelTypeName = 50, RuleSchemaName = 51, RuleVariable = 52, 
    RuleSymbolicName = 53, RuleUnescapedSymbolicName = 54, RuleEscapedSymbolicName = 55, 
    RuleLiteral = 56, RuleNumberLiteral = 57, RuleStringLiteral = 58, RuleBooleanLiteral = 59, 
    RuleMapLiteral = 60, RuleListLiteral = 61, RuleParameter = 62
  };

  CypherParser(antlr4::TokenStream *input);
  ~CypherParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CypherContext;
  class QueryContext;
  class SingleQueryContext;
  class SinglePartQueryContext;
  class ReadingClauseContext;
  class MatchClauseContext;
  class UpdatingClauseContext;
  class CreateClauseContext;
  class DeleteClauseContext;
  class SetClauseContext;
  class SetItemContext;
  class ReturnClauseContext;
  class ReturnBodyContext;
  class ReturnItemsContext;
  class ReturnItemContext;
  class WhereClauseContext;
  class OrderContext;
  class SortItemContext;
  class SkipContext;
  class LimitContext;
  class PatternContext;
  class PatternPartContext;
  class AnonymousPatternPartContext;
  class PatternElementContext;
  class PatternElementChainContext;
  class NodePatternContext;
  class RelationshipPatternContext;
  class ArrowHeadContext;
  class RelationshipDetailContext;
  class PropertiesContext;
  class NodeLabelsContext;
  class NodeLabelContext;
  class RelationshipTypesContext;
  class ExpressionContext;
  class OrExpressionContext;
  class XorExpressionContext;
  class AndExpressionContext;
  class NotExpressionContext;
  class ComparisonExpressionContext;
  class PartialComparisonExpressionContext;
  class AddOrSubtractExpressionContext;
  class MultiplyDivideModuloExpressionContext;
  class PowerOfExpressionContext;
  class UnaryAddOrSubtractExpressionContext;
  class AtomContext;
  class FunctionInvocationContext;
  class FunctionNameContext;
  class PropertyExpressionContext;
  class PropertyKeyNameContext;
  class LabelNameContext;
  class RelTypeNameContext;
  class SchemaNameContext;
  class VariableContext;
  class SymbolicNameContext;
  class UnescapedSymbolicNameContext;
  class EscapedSymbolicNameContext;
  class LiteralContext;
  class NumberLiteralContext;
  class StringLiteralContext;
  class BooleanLiteralContext;
  class MapLiteralContext;
  class ListLiteralContext;
  class ParameterContext; 

  class  CypherContext : public antlr4::ParserRuleContext {
  public:
    CypherContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QueryContext *query();
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CypherContext* cypher();

  class  QueryContext : public antlr4::ParserRuleContext {
  public:
    QueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleQueryContext *singleQuery();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QueryContext* query();

  class  SingleQueryContext : public antlr4::ParserRuleContext {
  public:
    SingleQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SinglePartQueryContext *singlePartQuery();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SingleQueryContext* singleQuery();

  class  SinglePartQueryContext : public antlr4::ParserRuleContext {
  public:
    SinglePartQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturnClauseContext *returnClause();
    std::vector<ReadingClauseContext *> readingClause();
    ReadingClauseContext* readingClause(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<UpdatingClauseContext *> updatingClause();
    UpdatingClauseContext* updatingClause(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SinglePartQueryContext* singlePartQuery();

  class  ReadingClauseContext : public antlr4::ParserRuleContext {
  public:
    ReadingClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MatchClauseContext *matchClause();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadingClauseContext* readingClause();

  class  MatchClauseContext : public antlr4::ParserRuleContext {
  public:
    MatchClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATCH();
    PatternContext *pattern();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    WhereClauseContext *whereClause();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatchClauseContext* matchClause();

  class  UpdatingClauseContext : public antlr4::ParserRuleContext {
  public:
    UpdatingClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CreateClauseContext *createClause();
    DeleteClauseContext *deleteClause();
    SetClauseContext *setClause();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UpdatingClauseContext* updatingClause();

  class  CreateClauseContext : public antlr4::ParserRuleContext {
  public:
    CreateClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    PatternContext *pattern();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CreateClauseContext* createClause();

  class  DeleteClauseContext : public antlr4::ParserRuleContext {
  public:
    DeleteClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DETACH();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeleteClauseContext* deleteClause();

  class  SetClauseContext : public antlr4::ParserRuleContext {
  public:
    SetClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    std::vector<SetItemContext *> setItem();
    SetItemContext* setItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetClauseContext* setClause();

  class  SetItemContext : public antlr4::ParserRuleContext {
  public:
    SetItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropertyExpressionContext *propertyExpression();
    antlr4::tree::TerminalNode *EQUAL();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    VariableContext *variable();
    NodeLabelsContext *nodeLabels();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetItemContext* setItem();

  class  ReturnClauseContext : public antlr4::ParserRuleContext {
  public:
    ReturnClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    ReturnBodyContext *returnBody();
    antlr4::tree::TerminalNode *DISTINCT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnClauseContext* returnClause();

  class  ReturnBodyContext : public antlr4::ParserRuleContext {
  public:
    ReturnBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturnItemsContext *returnItems();
    OrderContext *order();
    SkipContext *skip();
    LimitContext *limit();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnBodyContext* returnBody();

  class  ReturnItemsContext : public antlr4::ParserRuleContext {
  public:
    ReturnItemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ReturnItemContext *> returnItem();
    ReturnItemContext* returnItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnItemsContext* returnItems();

  class  ReturnItemContext : public antlr4::ParserRuleContext {
  public:
    ReturnItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *AS();
    VariableContext *variable();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnItemContext* returnItem();

  class  WhereClauseContext : public antlr4::ParserRuleContext {
  public:
    WhereClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHERE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhereClauseContext* whereClause();

  class  OrderContext : public antlr4::ParserRuleContext {
  public:
    OrderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ORDER();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *BY();
    std::vector<SortItemContext *> sortItem();
    SortItemContext* sortItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrderContext* order();

  class  SortItemContext : public antlr4::ParserRuleContext {
  public:
    SortItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *DESC();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortItemContext* sortItem();

  class  SkipContext : public antlr4::ParserRuleContext {
  public:
    SkipContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SKIP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SkipContext* skip();

  class  LimitContext : public antlr4::ParserRuleContext {
  public:
    LimitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIMIT();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LimitContext* limit();

  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PatternPartContext *> patternPart();
    PatternPartContext* patternPart(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternContext* pattern();

  class  PatternPartContext : public antlr4::ParserRuleContext {
  public:
    PatternPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *EQUAL();
    AnonymousPatternPartContext *anonymousPatternPart();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternPartContext* patternPart();

  class  AnonymousPatternPartContext : public antlr4::ParserRuleContext {
  public:
    AnonymousPatternPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PatternElementContext *patternElement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnonymousPatternPartContext* anonymousPatternPart();

  class  PatternElementContext : public antlr4::ParserRuleContext {
  public:
    PatternElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NodePatternContext *nodePattern();
    std::vector<PatternElementChainContext *> patternElementChain();
    PatternElementChainContext* patternElementChain(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternElementContext* patternElement();

  class  PatternElementChainContext : public antlr4::ParserRuleContext {
  public:
    PatternElementChainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationshipPatternContext *relationshipPattern();
    NodePatternContext *nodePattern();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternElementChainContext* patternElementChain();

  class  NodePatternContext : public antlr4::ParserRuleContext {
  public:
    NodePatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    VariableContext *variable();
    NodeLabelsContext *nodeLabels();
    PropertiesContext *properties();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodePatternContext* nodePattern();

  class  RelationshipPatternContext : public antlr4::ParserRuleContext {
  public:
    RelationshipPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DASH();
    antlr4::tree::TerminalNode* DASH(size_t i);
    ArrowHeadContext *arrowHead();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    RelationshipDetailContext *relationshipDetail();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationshipPatternContext* relationshipPattern();

  class  ArrowHeadContext : public antlr4::ParserRuleContext {
  public:
    ArrowHeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrowHeadContext* arrowHead();

  class  RelationshipDetailContext : public antlr4::ParserRuleContext {
  public:
    RelationshipDetailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    VariableContext *variable();
    RelationshipTypesContext *relationshipTypes();
    PropertiesContext *properties();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationshipDetailContext* relationshipDetail();

  class  PropertiesContext : public antlr4::ParserRuleContext {
  public:
    PropertiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MapLiteralContext *mapLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertiesContext* properties();

  class  NodeLabelsContext : public antlr4::ParserRuleContext {
  public:
    NodeLabelsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NodeLabelContext *> nodeLabel();
    NodeLabelContext* nodeLabel(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeLabelsContext* nodeLabels();

  class  NodeLabelContext : public antlr4::ParserRuleContext {
  public:
    NodeLabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    LabelNameContext *labelName();
    antlr4::tree::TerminalNode *SP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeLabelContext* nodeLabel();

  class  RelationshipTypesContext : public antlr4::ParserRuleContext {
  public:
    RelationshipTypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<RelTypeNameContext *> relTypeName();
    RelTypeNameContext* relTypeName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PIPE();
    antlr4::tree::TerminalNode* PIPE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationshipTypesContext* relationshipTypes();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OrExpressionContext *orExpression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  OrExpressionContext : public antlr4::ParserRuleContext {
  public:
    OrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<XorExpressionContext *> xorExpression();
    XorExpressionContext* xorExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrExpressionContext* orExpression();

  class  XorExpressionContext : public antlr4::ParserRuleContext {
  public:
    XorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AndExpressionContext *> andExpression();
    AndExpressionContext* andExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> XOR();
    antlr4::tree::TerminalNode* XOR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  XorExpressionContext* xorExpression();

  class  AndExpressionContext : public antlr4::ParserRuleContext {
  public:
    AndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NotExpressionContext *> notExpression();
    NotExpressionContext* notExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndExpressionContext* andExpression();

  class  NotExpressionContext : public antlr4::ParserRuleContext {
  public:
    NotExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ComparisonExpressionContext *comparisonExpression();
    std::vector<antlr4::tree::TerminalNode *> NOT();
    antlr4::tree::TerminalNode* NOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotExpressionContext* notExpression();

  class  ComparisonExpressionContext : public antlr4::ParserRuleContext {
  public:
    ComparisonExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddOrSubtractExpressionContext *addOrSubtractExpression();
    std::vector<PartialComparisonExpressionContext *> partialComparisonExpression();
    PartialComparisonExpressionContext* partialComparisonExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonExpressionContext* comparisonExpression();

  class  PartialComparisonExpressionContext : public antlr4::ParserRuleContext {
  public:
    PartialComparisonExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    AddOrSubtractExpressionContext *addOrSubtractExpression();
    antlr4::tree::TerminalNode *SP();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LTE();
    antlr4::tree::TerminalNode *GTE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PartialComparisonExpressionContext* partialComparisonExpression();

  class  AddOrSubtractExpressionContext : public antlr4::ParserRuleContext {
  public:
    AddOrSubtractExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiplyDivideModuloExpressionContext *> multiplyDivideModuloExpression();
    MultiplyDivideModuloExpressionContext* multiplyDivideModuloExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddOrSubtractExpressionContext* addOrSubtractExpression();

  class  MultiplyDivideModuloExpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiplyDivideModuloExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PowerOfExpressionContext *> powerOfExpression();
    PowerOfExpressionContext* powerOfExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SLASH();
    antlr4::tree::TerminalNode* SLASH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERCENT();
    antlr4::tree::TerminalNode* PERCENT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplyDivideModuloExpressionContext* multiplyDivideModuloExpression();

  class  PowerOfExpressionContext : public antlr4::ParserRuleContext {
  public:
    PowerOfExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UnaryAddOrSubtractExpressionContext *> unaryAddOrSubtractExpression();
    UnaryAddOrSubtractExpressionContext* unaryAddOrSubtractExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CARET();
    antlr4::tree::TerminalNode* CARET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PowerOfExpressionContext* powerOfExpression();

  class  UnaryAddOrSubtractExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryAddOrSubtractExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryAddOrSubtractExpressionContext* unaryAddOrSubtractExpression();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    ParameterContext *parameter();
    FunctionInvocationContext *functionInvocation();
    VariableContext *variable();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtomContext* atom();

  class  FunctionInvocationContext : public antlr4::ParserRuleContext {
  public:
    FunctionInvocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionNameContext *functionName();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *DISTINCT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionInvocationContext* functionInvocation();

  class  FunctionNameContext : public antlr4::ParserRuleContext {
  public:
    FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolicNameContext *symbolicName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionNameContext* functionName();

  class  PropertyExpressionContext : public antlr4::ParserRuleContext {
  public:
    PropertyExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<PropertyKeyNameContext *> propertyKeyName();
    PropertyKeyNameContext* propertyKeyName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyExpressionContext* propertyExpression();

  class  PropertyKeyNameContext : public antlr4::ParserRuleContext {
  public:
    PropertyKeyNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SchemaNameContext *schemaName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyKeyNameContext* propertyKeyName();

  class  LabelNameContext : public antlr4::ParserRuleContext {
  public:
    LabelNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SchemaNameContext *schemaName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelNameContext* labelName();

  class  RelTypeNameContext : public antlr4::ParserRuleContext {
  public:
    RelTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SchemaNameContext *schemaName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelTypeNameContext* relTypeName();

  class  SchemaNameContext : public antlr4::ParserRuleContext {
  public:
    SchemaNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolicNameContext *symbolicName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SchemaNameContext* schemaName();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolicNameContext *symbolicName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  SymbolicNameContext : public antlr4::ParserRuleContext {
  public:
    SymbolicNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnescapedSymbolicNameContext *unescapedSymbolicName();
    EscapedSymbolicNameContext *escapedSymbolicName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolicNameContext* symbolicName();

  class  UnescapedSymbolicNameContext : public antlr4::ParserRuleContext {
  public:
    UnescapedSymbolicNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnescapedSymbolicNameContext* unescapedSymbolicName();

  class  EscapedSymbolicNameContext : public antlr4::ParserRuleContext {
  public:
    EscapedSymbolicNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> BACKTICK();
    antlr4::tree::TerminalNode* BACKTICK(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EscapedSymbolicNameContext* escapedSymbolicName();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberLiteralContext *numberLiteral();
    StringLiteralContext *stringLiteral();
    BooleanLiteralContext *booleanLiteral();
    antlr4::tree::TerminalNode *NULL_();
    MapLiteralContext *mapLiteral();
    ListLiteralContext *listLiteral();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  NumberLiteralContext : public antlr4::ParserRuleContext {
  public:
    NumberLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOUBLE_LITERAL();
    antlr4::tree::TerminalNode *INTEGER_LITERAL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberLiteralContext* numberLiteral();

  class  StringLiteralContext : public antlr4::ParserRuleContext {
  public:
    StringLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLiteralContext* stringLiteral();

  class  BooleanLiteralContext : public antlr4::ParserRuleContext {
  public:
    BooleanLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE_();
    antlr4::tree::TerminalNode *FALSE_();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanLiteralContext* booleanLiteral();

  class  MapLiteralContext : public antlr4::ParserRuleContext {
  public:
    MapLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<PropertyKeyNameContext *> propertyKeyName();
    PropertyKeyNameContext* propertyKeyName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MapLiteralContext* mapLiteral();

  class  ListLiteralContext : public antlr4::ParserRuleContext {
  public:
    ListLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListLiteralContext* listLiteral();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOLLAR();
    SymbolicNameContext *symbolicName();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace parser
