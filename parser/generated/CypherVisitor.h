
// Generated from ./Cypher.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CypherParser.h"


namespace parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by CypherParser.
 */
class  CypherVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CypherParser.
   */
    virtual antlrcpp::Any visitCypher(CypherParser::CypherContext *context) = 0;

    virtual antlrcpp::Any visitQuery(CypherParser::QueryContext *context) = 0;

    virtual antlrcpp::Any visitSingleQuery(CypherParser::SingleQueryContext *context) = 0;

    virtual antlrcpp::Any visitSinglePartQuery(CypherParser::SinglePartQueryContext *context) = 0;

    virtual antlrcpp::Any visitReadingClause(CypherParser::ReadingClauseContext *context) = 0;

    virtual antlrcpp::Any visitMatchClause(CypherParser::MatchClauseContext *context) = 0;

    virtual antlrcpp::Any visitUpdatingClause(CypherParser::UpdatingClauseContext *context) = 0;

    virtual antlrcpp::Any visitCreateClause(CypherParser::CreateClauseContext *context) = 0;

    virtual antlrcpp::Any visitDeleteClause(CypherParser::DeleteClauseContext *context) = 0;

    virtual antlrcpp::Any visitSetClause(CypherParser::SetClauseContext *context) = 0;

    virtual antlrcpp::Any visitSetItem(CypherParser::SetItemContext *context) = 0;

    virtual antlrcpp::Any visitReturnClause(CypherParser::ReturnClauseContext *context) = 0;

    virtual antlrcpp::Any visitReturnBody(CypherParser::ReturnBodyContext *context) = 0;

    virtual antlrcpp::Any visitReturnItems(CypherParser::ReturnItemsContext *context) = 0;

    virtual antlrcpp::Any visitReturnItem(CypherParser::ReturnItemContext *context) = 0;

    virtual antlrcpp::Any visitWhereClause(CypherParser::WhereClauseContext *context) = 0;

    virtual antlrcpp::Any visitOrder(CypherParser::OrderContext *context) = 0;

    virtual antlrcpp::Any visitSortItem(CypherParser::SortItemContext *context) = 0;

    virtual antlrcpp::Any visitSkip(CypherParser::SkipContext *context) = 0;

    virtual antlrcpp::Any visitLimit(CypherParser::LimitContext *context) = 0;

    virtual antlrcpp::Any visitPattern(CypherParser::PatternContext *context) = 0;

    virtual antlrcpp::Any visitPatternPart(CypherParser::PatternPartContext *context) = 0;

    virtual antlrcpp::Any visitAnonymousPatternPart(CypherParser::AnonymousPatternPartContext *context) = 0;

    virtual antlrcpp::Any visitPatternElement(CypherParser::PatternElementContext *context) = 0;

    virtual antlrcpp::Any visitPatternElementChain(CypherParser::PatternElementChainContext *context) = 0;

    virtual antlrcpp::Any visitNodePattern(CypherParser::NodePatternContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipPattern(CypherParser::RelationshipPatternContext *context) = 0;

    virtual antlrcpp::Any visitArrowHead(CypherParser::ArrowHeadContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipDetail(CypherParser::RelationshipDetailContext *context) = 0;

    virtual antlrcpp::Any visitProperties(CypherParser::PropertiesContext *context) = 0;

    virtual antlrcpp::Any visitNodeLabels(CypherParser::NodeLabelsContext *context) = 0;

    virtual antlrcpp::Any visitNodeLabel(CypherParser::NodeLabelContext *context) = 0;

    virtual antlrcpp::Any visitRelationshipTypes(CypherParser::RelationshipTypesContext *context) = 0;

    virtual antlrcpp::Any visitExpression(CypherParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitOrExpression(CypherParser::OrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitXorExpression(CypherParser::XorExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAndExpression(CypherParser::AndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNotExpression(CypherParser::NotExpressionContext *context) = 0;

    virtual antlrcpp::Any visitComparisonExpression(CypherParser::ComparisonExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPartialComparisonExpression(CypherParser::PartialComparisonExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAddOrSubtractExpression(CypherParser::AddOrSubtractExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplyDivideModuloExpression(CypherParser::MultiplyDivideModuloExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPowerOfExpression(CypherParser::PowerOfExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryAddOrSubtractExpression(CypherParser::UnaryAddOrSubtractExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAtom(CypherParser::AtomContext *context) = 0;

    virtual antlrcpp::Any visitFunctionInvocation(CypherParser::FunctionInvocationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(CypherParser::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitPropertyExpression(CypherParser::PropertyExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPropertyKeyName(CypherParser::PropertyKeyNameContext *context) = 0;

    virtual antlrcpp::Any visitLabelName(CypherParser::LabelNameContext *context) = 0;

    virtual antlrcpp::Any visitRelTypeName(CypherParser::RelTypeNameContext *context) = 0;

    virtual antlrcpp::Any visitSchemaName(CypherParser::SchemaNameContext *context) = 0;

    virtual antlrcpp::Any visitVariable(CypherParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitSymbolicName(CypherParser::SymbolicNameContext *context) = 0;

    virtual antlrcpp::Any visitUnescapedSymbolicName(CypherParser::UnescapedSymbolicNameContext *context) = 0;

    virtual antlrcpp::Any visitEscapedSymbolicName(CypherParser::EscapedSymbolicNameContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(CypherParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitNumberLiteral(CypherParser::NumberLiteralContext *context) = 0;

    virtual antlrcpp::Any visitStringLiteral(CypherParser::StringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBooleanLiteral(CypherParser::BooleanLiteralContext *context) = 0;

    virtual antlrcpp::Any visitMapLiteral(CypherParser::MapLiteralContext *context) = 0;

    virtual antlrcpp::Any visitListLiteral(CypherParser::ListLiteralContext *context) = 0;

    virtual antlrcpp::Any visitParameter(CypherParser::ParameterContext *context) = 0;


};

}  // namespace parser
