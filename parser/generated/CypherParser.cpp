
// Generated from ./Cypher.g4 by ANTLR 4.7.2


#include "CypherVisitor.h"

#include "CypherParser.h"


using namespace antlrcpp;
using namespace parser;
using namespace antlr4;

CypherParser::CypherParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CypherParser::~CypherParser() {
  delete _interpreter;
}

std::string CypherParser::getGrammarFileName() const {
  return "Cypher.g4";
}

const std::vector<std::string>& CypherParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CypherParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CypherContext ------------------------------------------------------------------

CypherParser::CypherContext::CypherContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::QueryContext* CypherParser::CypherContext::query() {
  return getRuleContext<CypherParser::QueryContext>(0);
}

tree::TerminalNode* CypherParser::CypherContext::EOF() {
  return getToken(CypherParser::EOF, 0);
}

tree::TerminalNode* CypherParser::CypherContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::CypherContext::getRuleIndex() const {
  return CypherParser::RuleCypher;
}

antlrcpp::Any CypherParser::CypherContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitCypher(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::CypherContext* CypherParser::cypher() {
  CypherContext *_localctx = _tracker.createInstance<CypherContext>(_ctx, getState());
  enterRule(_localctx, 0, CypherParser::RuleCypher);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(126);
      match(CypherParser::SP);
    }
    setState(129);
    query();
    setState(130);
    match(CypherParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryContext ------------------------------------------------------------------

CypherParser::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SingleQueryContext* CypherParser::QueryContext::singleQuery() {
  return getRuleContext<CypherParser::SingleQueryContext>(0);
}


size_t CypherParser::QueryContext::getRuleIndex() const {
  return CypherParser::RuleQuery;
}

antlrcpp::Any CypherParser::QueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitQuery(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::QueryContext* CypherParser::query() {
  QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, getState());
  enterRule(_localctx, 2, CypherParser::RuleQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    singleQuery();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleQueryContext ------------------------------------------------------------------

CypherParser::SingleQueryContext::SingleQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SinglePartQueryContext* CypherParser::SingleQueryContext::singlePartQuery() {
  return getRuleContext<CypherParser::SinglePartQueryContext>(0);
}


size_t CypherParser::SingleQueryContext::getRuleIndex() const {
  return CypherParser::RuleSingleQuery;
}

antlrcpp::Any CypherParser::SingleQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSingleQuery(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SingleQueryContext* CypherParser::singleQuery() {
  SingleQueryContext *_localctx = _tracker.createInstance<SingleQueryContext>(_ctx, getState());
  enterRule(_localctx, 4, CypherParser::RuleSingleQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    singlePartQuery();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SinglePartQueryContext ------------------------------------------------------------------

CypherParser::SinglePartQueryContext::SinglePartQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::ReturnClauseContext* CypherParser::SinglePartQueryContext::returnClause() {
  return getRuleContext<CypherParser::ReturnClauseContext>(0);
}

std::vector<CypherParser::ReadingClauseContext *> CypherParser::SinglePartQueryContext::readingClause() {
  return getRuleContexts<CypherParser::ReadingClauseContext>();
}

CypherParser::ReadingClauseContext* CypherParser::SinglePartQueryContext::readingClause(size_t i) {
  return getRuleContext<CypherParser::ReadingClauseContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::SinglePartQueryContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::SinglePartQueryContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

std::vector<CypherParser::UpdatingClauseContext *> CypherParser::SinglePartQueryContext::updatingClause() {
  return getRuleContexts<CypherParser::UpdatingClauseContext>();
}

CypherParser::UpdatingClauseContext* CypherParser::SinglePartQueryContext::updatingClause(size_t i) {
  return getRuleContext<CypherParser::UpdatingClauseContext>(i);
}


size_t CypherParser::SinglePartQueryContext::getRuleIndex() const {
  return CypherParser::RuleSinglePartQuery;
}

antlrcpp::Any CypherParser::SinglePartQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSinglePartQuery(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SinglePartQueryContext* CypherParser::singlePartQuery() {
  SinglePartQueryContext *_localctx = _tracker.createInstance<SinglePartQueryContext>(_ctx, getState());
  enterRule(_localctx, 6, CypherParser::RuleSinglePartQuery);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CypherParser::MATCH) {
        setState(136);
        readingClause();
        setState(138);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(137);
          match(CypherParser::SP);
        }
        setState(144);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(145);
      returnClause();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CypherParser::MATCH) {
        setState(146);
        readingClause();
        setState(148);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(147);
          match(CypherParser::SP);
        }
        setState(154);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(155);
      updatingClause();
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(157);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(156);
            match(CypherParser::SP);
          }
          setState(159);
          updatingClause(); 
        }
        setState(164);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      }
      setState(169);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::RETURN

      || _la == CypherParser::SP) {
        setState(166);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(165);
          match(CypherParser::SP);
        }
        setState(168);
        returnClause();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadingClauseContext ------------------------------------------------------------------

CypherParser::ReadingClauseContext::ReadingClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::MatchClauseContext* CypherParser::ReadingClauseContext::matchClause() {
  return getRuleContext<CypherParser::MatchClauseContext>(0);
}


size_t CypherParser::ReadingClauseContext::getRuleIndex() const {
  return CypherParser::RuleReadingClause;
}

antlrcpp::Any CypherParser::ReadingClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitReadingClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ReadingClauseContext* CypherParser::readingClause() {
  ReadingClauseContext *_localctx = _tracker.createInstance<ReadingClauseContext>(_ctx, getState());
  enterRule(_localctx, 8, CypherParser::RuleReadingClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    matchClause();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatchClauseContext ------------------------------------------------------------------

CypherParser::MatchClauseContext::MatchClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::MatchClauseContext::MATCH() {
  return getToken(CypherParser::MATCH, 0);
}

CypherParser::PatternContext* CypherParser::MatchClauseContext::pattern() {
  return getRuleContext<CypherParser::PatternContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::MatchClauseContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::MatchClauseContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

CypherParser::WhereClauseContext* CypherParser::MatchClauseContext::whereClause() {
  return getRuleContext<CypherParser::WhereClauseContext>(0);
}


size_t CypherParser::MatchClauseContext::getRuleIndex() const {
  return CypherParser::RuleMatchClause;
}

antlrcpp::Any CypherParser::MatchClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitMatchClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::MatchClauseContext* CypherParser::matchClause() {
  MatchClauseContext *_localctx = _tracker.createInstance<MatchClauseContext>(_ctx, getState());
  enterRule(_localctx, 10, CypherParser::RuleMatchClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(CypherParser::MATCH);
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(176);
      match(CypherParser::SP);
    }
    setState(179);
    pattern();
    setState(184);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(180);
        match(CypherParser::SP);
      }
      setState(183);
      whereClause();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UpdatingClauseContext ------------------------------------------------------------------

CypherParser::UpdatingClauseContext::UpdatingClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::CreateClauseContext* CypherParser::UpdatingClauseContext::createClause() {
  return getRuleContext<CypherParser::CreateClauseContext>(0);
}

CypherParser::DeleteClauseContext* CypherParser::UpdatingClauseContext::deleteClause() {
  return getRuleContext<CypherParser::DeleteClauseContext>(0);
}

CypherParser::SetClauseContext* CypherParser::UpdatingClauseContext::setClause() {
  return getRuleContext<CypherParser::SetClauseContext>(0);
}


size_t CypherParser::UpdatingClauseContext::getRuleIndex() const {
  return CypherParser::RuleUpdatingClause;
}

antlrcpp::Any CypherParser::UpdatingClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitUpdatingClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::UpdatingClauseContext* CypherParser::updatingClause() {
  UpdatingClauseContext *_localctx = _tracker.createInstance<UpdatingClauseContext>(_ctx, getState());
  enterRule(_localctx, 12, CypherParser::RuleUpdatingClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CypherParser::CREATE: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        createClause();
        break;
      }

      case CypherParser::DELETE:
      case CypherParser::DETACH: {
        enterOuterAlt(_localctx, 2);
        setState(187);
        deleteClause();
        break;
      }

      case CypherParser::SET: {
        enterOuterAlt(_localctx, 3);
        setState(188);
        setClause();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateClauseContext ------------------------------------------------------------------

CypherParser::CreateClauseContext::CreateClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::CreateClauseContext::CREATE() {
  return getToken(CypherParser::CREATE, 0);
}

CypherParser::PatternContext* CypherParser::CreateClauseContext::pattern() {
  return getRuleContext<CypherParser::PatternContext>(0);
}

tree::TerminalNode* CypherParser::CreateClauseContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::CreateClauseContext::getRuleIndex() const {
  return CypherParser::RuleCreateClause;
}

antlrcpp::Any CypherParser::CreateClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitCreateClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::CreateClauseContext* CypherParser::createClause() {
  CreateClauseContext *_localctx = _tracker.createInstance<CreateClauseContext>(_ctx, getState());
  enterRule(_localctx, 14, CypherParser::RuleCreateClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(CypherParser::CREATE);
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(192);
      match(CypherParser::SP);
    }
    setState(195);
    pattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeleteClauseContext ------------------------------------------------------------------

CypherParser::DeleteClauseContext::DeleteClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::DeleteClauseContext::DELETE() {
  return getToken(CypherParser::DELETE, 0);
}

std::vector<CypherParser::ExpressionContext *> CypherParser::DeleteClauseContext::expression() {
  return getRuleContexts<CypherParser::ExpressionContext>();
}

CypherParser::ExpressionContext* CypherParser::DeleteClauseContext::expression(size_t i) {
  return getRuleContext<CypherParser::ExpressionContext>(i);
}

tree::TerminalNode* CypherParser::DeleteClauseContext::DETACH() {
  return getToken(CypherParser::DETACH, 0);
}

std::vector<tree::TerminalNode *> CypherParser::DeleteClauseContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::DeleteClauseContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

std::vector<tree::TerminalNode *> CypherParser::DeleteClauseContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::DeleteClauseContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}


size_t CypherParser::DeleteClauseContext::getRuleIndex() const {
  return CypherParser::RuleDeleteClause;
}

antlrcpp::Any CypherParser::DeleteClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitDeleteClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::DeleteClauseContext* CypherParser::deleteClause() {
  DeleteClauseContext *_localctx = _tracker.createInstance<DeleteClauseContext>(_ctx, getState());
  enterRule(_localctx, 16, CypherParser::RuleDeleteClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::DETACH) {
      setState(197);
      match(CypherParser::DETACH);
    }
    setState(200);
    match(CypherParser::DELETE);
    setState(202);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(201);
      match(CypherParser::SP);
    }
    setState(204);
    expression();
    setState(215);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(206);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(205);
          match(CypherParser::SP);
        }
        setState(208);
        match(CypherParser::COMMA);
        setState(210);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(209);
          match(CypherParser::SP);
        }
        setState(212);
        expression(); 
      }
      setState(217);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetClauseContext ------------------------------------------------------------------

CypherParser::SetClauseContext::SetClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::SetClauseContext::SET() {
  return getToken(CypherParser::SET, 0);
}

std::vector<CypherParser::SetItemContext *> CypherParser::SetClauseContext::setItem() {
  return getRuleContexts<CypherParser::SetItemContext>();
}

CypherParser::SetItemContext* CypherParser::SetClauseContext::setItem(size_t i) {
  return getRuleContext<CypherParser::SetItemContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::SetClauseContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::SetClauseContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

std::vector<tree::TerminalNode *> CypherParser::SetClauseContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::SetClauseContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}


size_t CypherParser::SetClauseContext::getRuleIndex() const {
  return CypherParser::RuleSetClause;
}

antlrcpp::Any CypherParser::SetClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSetClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SetClauseContext* CypherParser::setClause() {
  SetClauseContext *_localctx = _tracker.createInstance<SetClauseContext>(_ctx, getState());
  enterRule(_localctx, 18, CypherParser::RuleSetClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(CypherParser::SET);
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(219);
      match(CypherParser::SP);
    }
    setState(222);
    setItem();
    setState(233);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(224);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(223);
          match(CypherParser::SP);
        }
        setState(226);
        match(CypherParser::COMMA);
        setState(228);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(227);
          match(CypherParser::SP);
        }
        setState(230);
        setItem(); 
      }
      setState(235);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetItemContext ------------------------------------------------------------------

CypherParser::SetItemContext::SetItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::PropertyExpressionContext* CypherParser::SetItemContext::propertyExpression() {
  return getRuleContext<CypherParser::PropertyExpressionContext>(0);
}

tree::TerminalNode* CypherParser::SetItemContext::EQUAL() {
  return getToken(CypherParser::EQUAL, 0);
}

CypherParser::ExpressionContext* CypherParser::SetItemContext::expression() {
  return getRuleContext<CypherParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::SetItemContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::SetItemContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

CypherParser::VariableContext* CypherParser::SetItemContext::variable() {
  return getRuleContext<CypherParser::VariableContext>(0);
}

CypherParser::NodeLabelsContext* CypherParser::SetItemContext::nodeLabels() {
  return getRuleContext<CypherParser::NodeLabelsContext>(0);
}


size_t CypherParser::SetItemContext::getRuleIndex() const {
  return CypherParser::RuleSetItem;
}

antlrcpp::Any CypherParser::SetItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSetItem(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SetItemContext* CypherParser::setItem() {
  SetItemContext *_localctx = _tracker.createInstance<SetItemContext>(_ctx, getState());
  enterRule(_localctx, 20, CypherParser::RuleSetItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(236);
      propertyExpression();
      setState(238);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(237);
        match(CypherParser::SP);
      }
      setState(240);
      match(CypherParser::EQUAL);
      setState(242);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(241);
        match(CypherParser::SP);
      }
      setState(244);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(246);
      variable();
      setState(248);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(247);
        match(CypherParser::SP);
      }
      setState(250);
      match(CypherParser::EQUAL);
      setState(252);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(251);
        match(CypherParser::SP);
      }
      setState(254);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(256);
      variable();
      setState(258);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(257);
        match(CypherParser::SP);
      }
      setState(260);
      nodeLabels();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnClauseContext ------------------------------------------------------------------

CypherParser::ReturnClauseContext::ReturnClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::ReturnClauseContext::RETURN() {
  return getToken(CypherParser::RETURN, 0);
}

std::vector<tree::TerminalNode *> CypherParser::ReturnClauseContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::ReturnClauseContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

CypherParser::ReturnBodyContext* CypherParser::ReturnClauseContext::returnBody() {
  return getRuleContext<CypherParser::ReturnBodyContext>(0);
}

tree::TerminalNode* CypherParser::ReturnClauseContext::DISTINCT() {
  return getToken(CypherParser::DISTINCT, 0);
}


size_t CypherParser::ReturnClauseContext::getRuleIndex() const {
  return CypherParser::RuleReturnClause;
}

antlrcpp::Any CypherParser::ReturnClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitReturnClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ReturnClauseContext* CypherParser::returnClause() {
  ReturnClauseContext *_localctx = _tracker.createInstance<ReturnClauseContext>(_ctx, getState());
  enterRule(_localctx, 22, CypherParser::RuleReturnClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(CypherParser::RETURN);
    setState(269);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(266);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(265);
        match(CypherParser::SP);
      }
      setState(268);
      match(CypherParser::DISTINCT);
      break;
    }

    }
    setState(271);
    match(CypherParser::SP);
    setState(272);
    returnBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnBodyContext ------------------------------------------------------------------

CypherParser::ReturnBodyContext::ReturnBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::ReturnItemsContext* CypherParser::ReturnBodyContext::returnItems() {
  return getRuleContext<CypherParser::ReturnItemsContext>(0);
}

CypherParser::OrderContext* CypherParser::ReturnBodyContext::order() {
  return getRuleContext<CypherParser::OrderContext>(0);
}

CypherParser::SkipContext* CypherParser::ReturnBodyContext::skip() {
  return getRuleContext<CypherParser::SkipContext>(0);
}

CypherParser::LimitContext* CypherParser::ReturnBodyContext::limit() {
  return getRuleContext<CypherParser::LimitContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::ReturnBodyContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::ReturnBodyContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::ReturnBodyContext::getRuleIndex() const {
  return CypherParser::RuleReturnBody;
}

antlrcpp::Any CypherParser::ReturnBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitReturnBody(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ReturnBodyContext* CypherParser::returnBody() {
  ReturnBodyContext *_localctx = _tracker.createInstance<ReturnBodyContext>(_ctx, getState());
  enterRule(_localctx, 24, CypherParser::RuleReturnBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    returnItems();
    setState(279);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(275);
        match(CypherParser::SP);
      }
      setState(278);
      order();
      break;
    }

    }
    setState(285);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(282);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(281);
        match(CypherParser::SP);
      }
      setState(284);
      skip();
      break;
    }

    }
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::LIMIT

    || _la == CypherParser::SP) {
      setState(288);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(287);
        match(CypherParser::SP);
      }
      setState(290);
      limit();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnItemsContext ------------------------------------------------------------------

CypherParser::ReturnItemsContext::ReturnItemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::ReturnItemContext *> CypherParser::ReturnItemsContext::returnItem() {
  return getRuleContexts<CypherParser::ReturnItemContext>();
}

CypherParser::ReturnItemContext* CypherParser::ReturnItemsContext::returnItem(size_t i) {
  return getRuleContext<CypherParser::ReturnItemContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::ReturnItemsContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::ReturnItemsContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}

std::vector<tree::TerminalNode *> CypherParser::ReturnItemsContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::ReturnItemsContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::ReturnItemsContext::getRuleIndex() const {
  return CypherParser::RuleReturnItems;
}

antlrcpp::Any CypherParser::ReturnItemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitReturnItems(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ReturnItemsContext* CypherParser::returnItems() {
  ReturnItemsContext *_localctx = _tracker.createInstance<ReturnItemsContext>(_ctx, getState());
  enterRule(_localctx, 26, CypherParser::RuleReturnItems);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(308);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CypherParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(293);
        match(CypherParser::T__0);
        break;
      }

      case CypherParser::NOT:
      case CypherParser::NULL_:
      case CypherParser::TRUE_:
      case CypherParser::FALSE_:
      case CypherParser::PLUS:
      case CypherParser::MINUS:
      case CypherParser::DOLLAR:
      case CypherParser::LPAREN:
      case CypherParser::LBRACE:
      case CypherParser::LBRACK:
      case CypherParser::BACKTICK:
      case CypherParser::STRING:
      case CypherParser::INTEGER_LITERAL:
      case CypherParser::DOUBLE_LITERAL:
      case CypherParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(294);
        returnItem();
        setState(305);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(296);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == CypherParser::SP) {
              setState(295);
              match(CypherParser::SP);
            }
            setState(298);
            match(CypherParser::COMMA);
            setState(300);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == CypherParser::SP) {
              setState(299);
              match(CypherParser::SP);
            }
            setState(302);
            returnItem(); 
          }
          setState(307);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnItemContext ------------------------------------------------------------------

CypherParser::ReturnItemContext::ReturnItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::ExpressionContext* CypherParser::ReturnItemContext::expression() {
  return getRuleContext<CypherParser::ExpressionContext>(0);
}

tree::TerminalNode* CypherParser::ReturnItemContext::AS() {
  return getToken(CypherParser::AS, 0);
}

CypherParser::VariableContext* CypherParser::ReturnItemContext::variable() {
  return getRuleContext<CypherParser::VariableContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::ReturnItemContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::ReturnItemContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::ReturnItemContext::getRuleIndex() const {
  return CypherParser::RuleReturnItem;
}

antlrcpp::Any CypherParser::ReturnItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitReturnItem(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ReturnItemContext* CypherParser::returnItem() {
  ReturnItemContext *_localctx = _tracker.createInstance<ReturnItemContext>(_ctx, getState());
  enterRule(_localctx, 28, CypherParser::RuleReturnItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    expression();
    setState(319);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(312);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(311);
        match(CypherParser::SP);
      }
      setState(314);
      match(CypherParser::AS);
      setState(316);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(315);
        match(CypherParser::SP);
      }
      setState(318);
      variable();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereClauseContext ------------------------------------------------------------------

CypherParser::WhereClauseContext::WhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::WhereClauseContext::WHERE() {
  return getToken(CypherParser::WHERE, 0);
}

CypherParser::ExpressionContext* CypherParser::WhereClauseContext::expression() {
  return getRuleContext<CypherParser::ExpressionContext>(0);
}

tree::TerminalNode* CypherParser::WhereClauseContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::WhereClauseContext::getRuleIndex() const {
  return CypherParser::RuleWhereClause;
}

antlrcpp::Any CypherParser::WhereClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitWhereClause(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::WhereClauseContext* CypherParser::whereClause() {
  WhereClauseContext *_localctx = _tracker.createInstance<WhereClauseContext>(_ctx, getState());
  enterRule(_localctx, 30, CypherParser::RuleWhereClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(CypherParser::WHERE);
    setState(323);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(322);
      match(CypherParser::SP);
    }
    setState(325);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrderContext ------------------------------------------------------------------

CypherParser::OrderContext::OrderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::OrderContext::ORDER() {
  return getToken(CypherParser::ORDER, 0);
}

std::vector<tree::TerminalNode *> CypherParser::OrderContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::OrderContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

tree::TerminalNode* CypherParser::OrderContext::BY() {
  return getToken(CypherParser::BY, 0);
}

std::vector<CypherParser::SortItemContext *> CypherParser::OrderContext::sortItem() {
  return getRuleContexts<CypherParser::SortItemContext>();
}

CypherParser::SortItemContext* CypherParser::OrderContext::sortItem(size_t i) {
  return getRuleContext<CypherParser::SortItemContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::OrderContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::OrderContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}


size_t CypherParser::OrderContext::getRuleIndex() const {
  return CypherParser::RuleOrder;
}

antlrcpp::Any CypherParser::OrderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitOrder(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::OrderContext* CypherParser::order() {
  OrderContext *_localctx = _tracker.createInstance<OrderContext>(_ctx, getState());
  enterRule(_localctx, 32, CypherParser::RuleOrder);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(327);
    match(CypherParser::ORDER);
    setState(328);
    match(CypherParser::SP);
    setState(329);
    match(CypherParser::BY);
    setState(330);
    match(CypherParser::SP);
    setState(331);
    sortItem();
    setState(342);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(333);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(332);
          match(CypherParser::SP);
        }
        setState(335);
        match(CypherParser::COMMA);
        setState(337);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(336);
          match(CypherParser::SP);
        }
        setState(339);
        sortItem(); 
      }
      setState(344);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortItemContext ------------------------------------------------------------------

CypherParser::SortItemContext::SortItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::ExpressionContext* CypherParser::SortItemContext::expression() {
  return getRuleContext<CypherParser::ExpressionContext>(0);
}

tree::TerminalNode* CypherParser::SortItemContext::ASC() {
  return getToken(CypherParser::ASC, 0);
}

tree::TerminalNode* CypherParser::SortItemContext::DESC() {
  return getToken(CypherParser::DESC, 0);
}

tree::TerminalNode* CypherParser::SortItemContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::SortItemContext::getRuleIndex() const {
  return CypherParser::RuleSortItem;
}

antlrcpp::Any CypherParser::SortItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSortItem(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SortItemContext* CypherParser::sortItem() {
  SortItemContext *_localctx = _tracker.createInstance<SortItemContext>(_ctx, getState());
  enterRule(_localctx, 34, CypherParser::RuleSortItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    expression();
    setState(354);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(347);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(346);
        match(CypherParser::SP);
      }
      setState(349);
      match(CypherParser::ASC);
      break;
    }

    case 2: {
      setState(351);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(350);
        match(CypherParser::SP);
      }
      setState(353);
      match(CypherParser::DESC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SkipContext ------------------------------------------------------------------

CypherParser::SkipContext::SkipContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::SkipContext::SKIP() {
  return getToken(CypherParser::SKIP, 0);
}

CypherParser::ExpressionContext* CypherParser::SkipContext::expression() {
  return getRuleContext<CypherParser::ExpressionContext>(0);
}

tree::TerminalNode* CypherParser::SkipContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::SkipContext::getRuleIndex() const {
  return CypherParser::RuleSkip;
}

antlrcpp::Any CypherParser::SkipContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSkip(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SkipContext* CypherParser::skip() {
  SkipContext *_localctx = _tracker.createInstance<SkipContext>(_ctx, getState());
  enterRule(_localctx, 36, CypherParser::RuleSkip);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(CypherParser::SKIP);
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(357);
      match(CypherParser::SP);
    }
    setState(360);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LimitContext ------------------------------------------------------------------

CypherParser::LimitContext::LimitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::LimitContext::LIMIT() {
  return getToken(CypherParser::LIMIT, 0);
}

CypherParser::ExpressionContext* CypherParser::LimitContext::expression() {
  return getRuleContext<CypherParser::ExpressionContext>(0);
}

tree::TerminalNode* CypherParser::LimitContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::LimitContext::getRuleIndex() const {
  return CypherParser::RuleLimit;
}

antlrcpp::Any CypherParser::LimitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitLimit(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::LimitContext* CypherParser::limit() {
  LimitContext *_localctx = _tracker.createInstance<LimitContext>(_ctx, getState());
  enterRule(_localctx, 38, CypherParser::RuleLimit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    match(CypherParser::LIMIT);
    setState(364);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(363);
      match(CypherParser::SP);
    }
    setState(366);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternContext ------------------------------------------------------------------

CypherParser::PatternContext::PatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::PatternPartContext *> CypherParser::PatternContext::patternPart() {
  return getRuleContexts<CypherParser::PatternPartContext>();
}

CypherParser::PatternPartContext* CypherParser::PatternContext::patternPart(size_t i) {
  return getRuleContext<CypherParser::PatternPartContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::PatternContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::PatternContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}

std::vector<tree::TerminalNode *> CypherParser::PatternContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::PatternContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::PatternContext::getRuleIndex() const {
  return CypherParser::RulePattern;
}

antlrcpp::Any CypherParser::PatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPattern(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PatternContext* CypherParser::pattern() {
  PatternContext *_localctx = _tracker.createInstance<PatternContext>(_ctx, getState());
  enterRule(_localctx, 40, CypherParser::RulePattern);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(368);
    patternPart();
    setState(379);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(370);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(369);
          match(CypherParser::SP);
        }
        setState(372);
        match(CypherParser::COMMA);
        setState(374);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(373);
          match(CypherParser::SP);
        }
        setState(376);
        patternPart(); 
      }
      setState(381);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternPartContext ------------------------------------------------------------------

CypherParser::PatternPartContext::PatternPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::VariableContext* CypherParser::PatternPartContext::variable() {
  return getRuleContext<CypherParser::VariableContext>(0);
}

tree::TerminalNode* CypherParser::PatternPartContext::EQUAL() {
  return getToken(CypherParser::EQUAL, 0);
}

CypherParser::AnonymousPatternPartContext* CypherParser::PatternPartContext::anonymousPatternPart() {
  return getRuleContext<CypherParser::AnonymousPatternPartContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::PatternPartContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::PatternPartContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::PatternPartContext::getRuleIndex() const {
  return CypherParser::RulePatternPart;
}

antlrcpp::Any CypherParser::PatternPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPatternPart(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PatternPartContext* CypherParser::patternPart() {
  PatternPartContext *_localctx = _tracker.createInstance<PatternPartContext>(_ctx, getState());
  enterRule(_localctx, 42, CypherParser::RulePatternPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CypherParser::BACKTICK:
      case CypherParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(382);
        variable();
        setState(384);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(383);
          match(CypherParser::SP);
        }
        setState(386);
        match(CypherParser::EQUAL);
        setState(388);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(387);
          match(CypherParser::SP);
        }
        setState(390);
        anonymousPatternPart();
        break;
      }

      case CypherParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(392);
        anonymousPatternPart();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnonymousPatternPartContext ------------------------------------------------------------------

CypherParser::AnonymousPatternPartContext::AnonymousPatternPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::PatternElementContext* CypherParser::AnonymousPatternPartContext::patternElement() {
  return getRuleContext<CypherParser::PatternElementContext>(0);
}


size_t CypherParser::AnonymousPatternPartContext::getRuleIndex() const {
  return CypherParser::RuleAnonymousPatternPart;
}

antlrcpp::Any CypherParser::AnonymousPatternPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitAnonymousPatternPart(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::AnonymousPatternPartContext* CypherParser::anonymousPatternPart() {
  AnonymousPatternPartContext *_localctx = _tracker.createInstance<AnonymousPatternPartContext>(_ctx, getState());
  enterRule(_localctx, 44, CypherParser::RuleAnonymousPatternPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    patternElement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternElementContext ------------------------------------------------------------------

CypherParser::PatternElementContext::PatternElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::NodePatternContext* CypherParser::PatternElementContext::nodePattern() {
  return getRuleContext<CypherParser::NodePatternContext>(0);
}

std::vector<CypherParser::PatternElementChainContext *> CypherParser::PatternElementContext::patternElementChain() {
  return getRuleContexts<CypherParser::PatternElementChainContext>();
}

CypherParser::PatternElementChainContext* CypherParser::PatternElementContext::patternElementChain(size_t i) {
  return getRuleContext<CypherParser::PatternElementChainContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::PatternElementContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::PatternElementContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::PatternElementContext::getRuleIndex() const {
  return CypherParser::RulePatternElement;
}

antlrcpp::Any CypherParser::PatternElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPatternElement(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PatternElementContext* CypherParser::patternElement() {
  PatternElementContext *_localctx = _tracker.createInstance<PatternElementContext>(_ctx, getState());
  enterRule(_localctx, 46, CypherParser::RulePatternElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(397);
    nodePattern();
    setState(404);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(399);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(398);
          match(CypherParser::SP);
        }
        setState(401);
        patternElementChain(); 
      }
      setState(406);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternElementChainContext ------------------------------------------------------------------

CypherParser::PatternElementChainContext::PatternElementChainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::RelationshipPatternContext* CypherParser::PatternElementChainContext::relationshipPattern() {
  return getRuleContext<CypherParser::RelationshipPatternContext>(0);
}

CypherParser::NodePatternContext* CypherParser::PatternElementChainContext::nodePattern() {
  return getRuleContext<CypherParser::NodePatternContext>(0);
}

tree::TerminalNode* CypherParser::PatternElementChainContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::PatternElementChainContext::getRuleIndex() const {
  return CypherParser::RulePatternElementChain;
}

antlrcpp::Any CypherParser::PatternElementChainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPatternElementChain(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PatternElementChainContext* CypherParser::patternElementChain() {
  PatternElementChainContext *_localctx = _tracker.createInstance<PatternElementChainContext>(_ctx, getState());
  enterRule(_localctx, 48, CypherParser::RulePatternElementChain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    relationshipPattern();
    setState(409);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(408);
      match(CypherParser::SP);
    }
    setState(411);
    nodePattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodePatternContext ------------------------------------------------------------------

CypherParser::NodePatternContext::NodePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::NodePatternContext::LPAREN() {
  return getToken(CypherParser::LPAREN, 0);
}

tree::TerminalNode* CypherParser::NodePatternContext::RPAREN() {
  return getToken(CypherParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> CypherParser::NodePatternContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::NodePatternContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

CypherParser::VariableContext* CypherParser::NodePatternContext::variable() {
  return getRuleContext<CypherParser::VariableContext>(0);
}

CypherParser::NodeLabelsContext* CypherParser::NodePatternContext::nodeLabels() {
  return getRuleContext<CypherParser::NodeLabelsContext>(0);
}

CypherParser::PropertiesContext* CypherParser::NodePatternContext::properties() {
  return getRuleContext<CypherParser::PropertiesContext>(0);
}


size_t CypherParser::NodePatternContext::getRuleIndex() const {
  return CypherParser::RuleNodePattern;
}

antlrcpp::Any CypherParser::NodePatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitNodePattern(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::NodePatternContext* CypherParser::nodePattern() {
  NodePatternContext *_localctx = _tracker.createInstance<NodePatternContext>(_ctx, getState());
  enterRule(_localctx, 50, CypherParser::RuleNodePattern);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    match(CypherParser::LPAREN);
    setState(415);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      setState(414);
      match(CypherParser::SP);
      break;
    }

    }
    setState(418);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::BACKTICK

    || _la == CypherParser::IDENTIFIER) {
      setState(417);
      variable();
    }
    setState(421);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      setState(420);
      match(CypherParser::SP);
      break;
    }

    }
    setState(424);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::COLON) {
      setState(423);
      nodeLabels();
    }
    setState(427);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      setState(426);
      match(CypherParser::SP);
      break;
    }

    }
    setState(430);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::LBRACE) {
      setState(429);
      properties();
    }
    setState(433);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(432);
      match(CypherParser::SP);
    }
    setState(435);
    match(CypherParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipPatternContext ------------------------------------------------------------------

CypherParser::RelationshipPatternContext::RelationshipPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CypherParser::RelationshipPatternContext::DASH() {
  return getTokens(CypherParser::DASH);
}

tree::TerminalNode* CypherParser::RelationshipPatternContext::DASH(size_t i) {
  return getToken(CypherParser::DASH, i);
}

CypherParser::ArrowHeadContext* CypherParser::RelationshipPatternContext::arrowHead() {
  return getRuleContext<CypherParser::ArrowHeadContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::RelationshipPatternContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::RelationshipPatternContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

CypherParser::RelationshipDetailContext* CypherParser::RelationshipPatternContext::relationshipDetail() {
  return getRuleContext<CypherParser::RelationshipDetailContext>(0);
}


size_t CypherParser::RelationshipPatternContext::getRuleIndex() const {
  return CypherParser::RuleRelationshipPattern;
}

antlrcpp::Any CypherParser::RelationshipPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipPattern(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::RelationshipPatternContext* CypherParser::relationshipPattern() {
  RelationshipPatternContext *_localctx = _tracker.createInstance<RelationshipPatternContext>(_ctx, getState());
  enterRule(_localctx, 52, CypherParser::RuleRelationshipPattern);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(479);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(437);
      match(CypherParser::DASH);
      setState(439);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
      case 1: {
        setState(438);
        match(CypherParser::SP);
        break;
      }

      }
      setState(442);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::LBRACK) {
        setState(441);
        relationshipDetail();
      }
      setState(445);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(444);
        match(CypherParser::SP);
      }
      setState(447);
      match(CypherParser::DASH);
      setState(449);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(448);
        match(CypherParser::SP);
      }
      setState(451);
      arrowHead();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(452);
      arrowHead();
      setState(454);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(453);
        match(CypherParser::SP);
      }
      setState(456);
      match(CypherParser::DASH);
      setState(458);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
      case 1: {
        setState(457);
        match(CypherParser::SP);
        break;
      }

      }
      setState(461);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::LBRACK) {
        setState(460);
        relationshipDetail();
      }
      setState(464);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(463);
        match(CypherParser::SP);
      }
      setState(466);
      match(CypherParser::DASH);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(468);
      match(CypherParser::DASH);
      setState(470);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
      case 1: {
        setState(469);
        match(CypherParser::SP);
        break;
      }

      }
      setState(473);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::LBRACK) {
        setState(472);
        relationshipDetail();
      }
      setState(476);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(475);
        match(CypherParser::SP);
      }
      setState(478);
      match(CypherParser::DASH);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrowHeadContext ------------------------------------------------------------------

CypherParser::ArrowHeadContext::ArrowHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::ArrowHeadContext::LT() {
  return getToken(CypherParser::LT, 0);
}

tree::TerminalNode* CypherParser::ArrowHeadContext::MINUS() {
  return getToken(CypherParser::MINUS, 0);
}

tree::TerminalNode* CypherParser::ArrowHeadContext::GT() {
  return getToken(CypherParser::GT, 0);
}


size_t CypherParser::ArrowHeadContext::getRuleIndex() const {
  return CypherParser::RuleArrowHead;
}

antlrcpp::Any CypherParser::ArrowHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitArrowHead(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ArrowHeadContext* CypherParser::arrowHead() {
  ArrowHeadContext *_localctx = _tracker.createInstance<ArrowHeadContext>(_ctx, getState());
  enterRule(_localctx, 54, CypherParser::RuleArrowHead);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(486);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CypherParser::LT: {
        enterOuterAlt(_localctx, 1);
        setState(481);
        match(CypherParser::LT);
        setState(482);
        match(CypherParser::MINUS);
        setState(483);
        match(CypherParser::GT);
        break;
      }

      case CypherParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(484);
        match(CypherParser::MINUS);
        setState(485);
        match(CypherParser::GT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipDetailContext ------------------------------------------------------------------

CypherParser::RelationshipDetailContext::RelationshipDetailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::RelationshipDetailContext::LBRACK() {
  return getToken(CypherParser::LBRACK, 0);
}

tree::TerminalNode* CypherParser::RelationshipDetailContext::RBRACK() {
  return getToken(CypherParser::RBRACK, 0);
}

std::vector<tree::TerminalNode *> CypherParser::RelationshipDetailContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::RelationshipDetailContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

CypherParser::VariableContext* CypherParser::RelationshipDetailContext::variable() {
  return getRuleContext<CypherParser::VariableContext>(0);
}

CypherParser::RelationshipTypesContext* CypherParser::RelationshipDetailContext::relationshipTypes() {
  return getRuleContext<CypherParser::RelationshipTypesContext>(0);
}

CypherParser::PropertiesContext* CypherParser::RelationshipDetailContext::properties() {
  return getRuleContext<CypherParser::PropertiesContext>(0);
}


size_t CypherParser::RelationshipDetailContext::getRuleIndex() const {
  return CypherParser::RuleRelationshipDetail;
}

antlrcpp::Any CypherParser::RelationshipDetailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipDetail(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::RelationshipDetailContext* CypherParser::relationshipDetail() {
  RelationshipDetailContext *_localctx = _tracker.createInstance<RelationshipDetailContext>(_ctx, getState());
  enterRule(_localctx, 56, CypherParser::RuleRelationshipDetail);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    match(CypherParser::LBRACK);
    setState(490);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      setState(489);
      match(CypherParser::SP);
      break;
    }

    }
    setState(493);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::BACKTICK

    || _la == CypherParser::IDENTIFIER) {
      setState(492);
      variable();
    }
    setState(496);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      setState(495);
      match(CypherParser::SP);
      break;
    }

    }
    setState(499);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::COLON) {
      setState(498);
      relationshipTypes();
    }
    setState(502);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(501);
      match(CypherParser::SP);
      break;
    }

    }
    setState(505);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::LBRACE) {
      setState(504);
      properties();
    }
    setState(508);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(507);
      match(CypherParser::SP);
    }
    setState(510);
    match(CypherParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertiesContext ------------------------------------------------------------------

CypherParser::PropertiesContext::PropertiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::MapLiteralContext* CypherParser::PropertiesContext::mapLiteral() {
  return getRuleContext<CypherParser::MapLiteralContext>(0);
}


size_t CypherParser::PropertiesContext::getRuleIndex() const {
  return CypherParser::RuleProperties;
}

antlrcpp::Any CypherParser::PropertiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitProperties(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PropertiesContext* CypherParser::properties() {
  PropertiesContext *_localctx = _tracker.createInstance<PropertiesContext>(_ctx, getState());
  enterRule(_localctx, 58, CypherParser::RuleProperties);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    mapLiteral();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeLabelsContext ------------------------------------------------------------------

CypherParser::NodeLabelsContext::NodeLabelsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::NodeLabelContext *> CypherParser::NodeLabelsContext::nodeLabel() {
  return getRuleContexts<CypherParser::NodeLabelContext>();
}

CypherParser::NodeLabelContext* CypherParser::NodeLabelsContext::nodeLabel(size_t i) {
  return getRuleContext<CypherParser::NodeLabelContext>(i);
}


size_t CypherParser::NodeLabelsContext::getRuleIndex() const {
  return CypherParser::RuleNodeLabels;
}

antlrcpp::Any CypherParser::NodeLabelsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitNodeLabels(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::NodeLabelsContext* CypherParser::nodeLabels() {
  NodeLabelsContext *_localctx = _tracker.createInstance<NodeLabelsContext>(_ctx, getState());
  enterRule(_localctx, 60, CypherParser::RuleNodeLabels);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(514);
      nodeLabel();
      setState(517); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CypherParser::COLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeLabelContext ------------------------------------------------------------------

CypherParser::NodeLabelContext::NodeLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::NodeLabelContext::COLON() {
  return getToken(CypherParser::COLON, 0);
}

CypherParser::LabelNameContext* CypherParser::NodeLabelContext::labelName() {
  return getRuleContext<CypherParser::LabelNameContext>(0);
}

tree::TerminalNode* CypherParser::NodeLabelContext::SP() {
  return getToken(CypherParser::SP, 0);
}


size_t CypherParser::NodeLabelContext::getRuleIndex() const {
  return CypherParser::RuleNodeLabel;
}

antlrcpp::Any CypherParser::NodeLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitNodeLabel(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::NodeLabelContext* CypherParser::nodeLabel() {
  NodeLabelContext *_localctx = _tracker.createInstance<NodeLabelContext>(_ctx, getState());
  enterRule(_localctx, 62, CypherParser::RuleNodeLabel);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(519);
    match(CypherParser::COLON);
    setState(521);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(520);
      match(CypherParser::SP);
    }
    setState(523);
    labelName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipTypesContext ------------------------------------------------------------------

CypherParser::RelationshipTypesContext::RelationshipTypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CypherParser::RelationshipTypesContext::COLON() {
  return getTokens(CypherParser::COLON);
}

tree::TerminalNode* CypherParser::RelationshipTypesContext::COLON(size_t i) {
  return getToken(CypherParser::COLON, i);
}

std::vector<CypherParser::RelTypeNameContext *> CypherParser::RelationshipTypesContext::relTypeName() {
  return getRuleContexts<CypherParser::RelTypeNameContext>();
}

CypherParser::RelTypeNameContext* CypherParser::RelationshipTypesContext::relTypeName(size_t i) {
  return getRuleContext<CypherParser::RelTypeNameContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::RelationshipTypesContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::RelationshipTypesContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

std::vector<tree::TerminalNode *> CypherParser::RelationshipTypesContext::PIPE() {
  return getTokens(CypherParser::PIPE);
}

tree::TerminalNode* CypherParser::RelationshipTypesContext::PIPE(size_t i) {
  return getToken(CypherParser::PIPE, i);
}


size_t CypherParser::RelationshipTypesContext::getRuleIndex() const {
  return CypherParser::RuleRelationshipTypes;
}

antlrcpp::Any CypherParser::RelationshipTypesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipTypes(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::RelationshipTypesContext* CypherParser::relationshipTypes() {
  RelationshipTypesContext *_localctx = _tracker.createInstance<RelationshipTypesContext>(_ctx, getState());
  enterRule(_localctx, 64, CypherParser::RuleRelationshipTypes);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(525);
    match(CypherParser::COLON);
    setState(527);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(526);
      match(CypherParser::SP);
    }
    setState(529);
    relTypeName();
    setState(546);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(531);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(530);
          match(CypherParser::SP);
        }
        setState(533);
        match(CypherParser::PIPE);
        setState(535);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
        case 1: {
          setState(534);
          match(CypherParser::SP);
          break;
        }

        }
        setState(538);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::COLON) {
          setState(537);
          match(CypherParser::COLON);
        }
        setState(541);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(540);
          match(CypherParser::SP);
        }
        setState(543);
        relTypeName(); 
      }
      setState(548);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CypherParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::OrExpressionContext* CypherParser::ExpressionContext::orExpression() {
  return getRuleContext<CypherParser::OrExpressionContext>(0);
}


size_t CypherParser::ExpressionContext::getRuleIndex() const {
  return CypherParser::RuleExpression;
}

antlrcpp::Any CypherParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ExpressionContext* CypherParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 66, CypherParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(549);
    orExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrExpressionContext ------------------------------------------------------------------

CypherParser::OrExpressionContext::OrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::XorExpressionContext *> CypherParser::OrExpressionContext::xorExpression() {
  return getRuleContexts<CypherParser::XorExpressionContext>();
}

CypherParser::XorExpressionContext* CypherParser::OrExpressionContext::xorExpression(size_t i) {
  return getRuleContext<CypherParser::XorExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::OrExpressionContext::OR() {
  return getTokens(CypherParser::OR);
}

tree::TerminalNode* CypherParser::OrExpressionContext::OR(size_t i) {
  return getToken(CypherParser::OR, i);
}

std::vector<tree::TerminalNode *> CypherParser::OrExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::OrExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::OrExpressionContext::getRuleIndex() const {
  return CypherParser::RuleOrExpression;
}

antlrcpp::Any CypherParser::OrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitOrExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::OrExpressionContext* CypherParser::orExpression() {
  OrExpressionContext *_localctx = _tracker.createInstance<OrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 68, CypherParser::RuleOrExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(551);
    xorExpression();
    setState(562);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(553);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(552);
          match(CypherParser::SP);
        }
        setState(555);
        match(CypherParser::OR);
        setState(557);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(556);
          match(CypherParser::SP);
        }
        setState(559);
        xorExpression(); 
      }
      setState(564);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XorExpressionContext ------------------------------------------------------------------

CypherParser::XorExpressionContext::XorExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::AndExpressionContext *> CypherParser::XorExpressionContext::andExpression() {
  return getRuleContexts<CypherParser::AndExpressionContext>();
}

CypherParser::AndExpressionContext* CypherParser::XorExpressionContext::andExpression(size_t i) {
  return getRuleContext<CypherParser::AndExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::XorExpressionContext::XOR() {
  return getTokens(CypherParser::XOR);
}

tree::TerminalNode* CypherParser::XorExpressionContext::XOR(size_t i) {
  return getToken(CypherParser::XOR, i);
}

std::vector<tree::TerminalNode *> CypherParser::XorExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::XorExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::XorExpressionContext::getRuleIndex() const {
  return CypherParser::RuleXorExpression;
}

antlrcpp::Any CypherParser::XorExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitXorExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::XorExpressionContext* CypherParser::xorExpression() {
  XorExpressionContext *_localctx = _tracker.createInstance<XorExpressionContext>(_ctx, getState());
  enterRule(_localctx, 70, CypherParser::RuleXorExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(565);
    andExpression();
    setState(576);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(567);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(566);
          match(CypherParser::SP);
        }
        setState(569);
        match(CypherParser::XOR);
        setState(571);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(570);
          match(CypherParser::SP);
        }
        setState(573);
        andExpression(); 
      }
      setState(578);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndExpressionContext ------------------------------------------------------------------

CypherParser::AndExpressionContext::AndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::NotExpressionContext *> CypherParser::AndExpressionContext::notExpression() {
  return getRuleContexts<CypherParser::NotExpressionContext>();
}

CypherParser::NotExpressionContext* CypherParser::AndExpressionContext::notExpression(size_t i) {
  return getRuleContext<CypherParser::NotExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::AndExpressionContext::AND() {
  return getTokens(CypherParser::AND);
}

tree::TerminalNode* CypherParser::AndExpressionContext::AND(size_t i) {
  return getToken(CypherParser::AND, i);
}

std::vector<tree::TerminalNode *> CypherParser::AndExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::AndExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::AndExpressionContext::getRuleIndex() const {
  return CypherParser::RuleAndExpression;
}

antlrcpp::Any CypherParser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::AndExpressionContext* CypherParser::andExpression() {
  AndExpressionContext *_localctx = _tracker.createInstance<AndExpressionContext>(_ctx, getState());
  enterRule(_localctx, 72, CypherParser::RuleAndExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(579);
    notExpression();
    setState(590);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(581);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(580);
          match(CypherParser::SP);
        }
        setState(583);
        match(CypherParser::AND);
        setState(585);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(584);
          match(CypherParser::SP);
        }
        setState(587);
        notExpression(); 
      }
      setState(592);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotExpressionContext ------------------------------------------------------------------

CypherParser::NotExpressionContext::NotExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::ComparisonExpressionContext* CypherParser::NotExpressionContext::comparisonExpression() {
  return getRuleContext<CypherParser::ComparisonExpressionContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::NotExpressionContext::NOT() {
  return getTokens(CypherParser::NOT);
}

tree::TerminalNode* CypherParser::NotExpressionContext::NOT(size_t i) {
  return getToken(CypherParser::NOT, i);
}

std::vector<tree::TerminalNode *> CypherParser::NotExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::NotExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::NotExpressionContext::getRuleIndex() const {
  return CypherParser::RuleNotExpression;
}

antlrcpp::Any CypherParser::NotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitNotExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::NotExpressionContext* CypherParser::notExpression() {
  NotExpressionContext *_localctx = _tracker.createInstance<NotExpressionContext>(_ctx, getState());
  enterRule(_localctx, 74, CypherParser::RuleNotExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(599);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CypherParser::NOT) {
      setState(593);
      match(CypherParser::NOT);
      setState(595);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(594);
        match(CypherParser::SP);
      }
      setState(601);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(602);
    comparisonExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonExpressionContext ------------------------------------------------------------------

CypherParser::ComparisonExpressionContext::ComparisonExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::AddOrSubtractExpressionContext* CypherParser::ComparisonExpressionContext::addOrSubtractExpression() {
  return getRuleContext<CypherParser::AddOrSubtractExpressionContext>(0);
}

std::vector<CypherParser::PartialComparisonExpressionContext *> CypherParser::ComparisonExpressionContext::partialComparisonExpression() {
  return getRuleContexts<CypherParser::PartialComparisonExpressionContext>();
}

CypherParser::PartialComparisonExpressionContext* CypherParser::ComparisonExpressionContext::partialComparisonExpression(size_t i) {
  return getRuleContext<CypherParser::PartialComparisonExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::ComparisonExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::ComparisonExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::ComparisonExpressionContext::getRuleIndex() const {
  return CypherParser::RuleComparisonExpression;
}

antlrcpp::Any CypherParser::ComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitComparisonExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ComparisonExpressionContext* CypherParser::comparisonExpression() {
  ComparisonExpressionContext *_localctx = _tracker.createInstance<ComparisonExpressionContext>(_ctx, getState());
  enterRule(_localctx, 76, CypherParser::RuleComparisonExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(604);
    addOrSubtractExpression();
    setState(611);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(606);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(605);
          match(CypherParser::SP);
        }
        setState(608);
        partialComparisonExpression(); 
      }
      setState(613);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PartialComparisonExpressionContext ------------------------------------------------------------------

CypherParser::PartialComparisonExpressionContext::PartialComparisonExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::PartialComparisonExpressionContext::EQUAL() {
  return getToken(CypherParser::EQUAL, 0);
}

CypherParser::AddOrSubtractExpressionContext* CypherParser::PartialComparisonExpressionContext::addOrSubtractExpression() {
  return getRuleContext<CypherParser::AddOrSubtractExpressionContext>(0);
}

tree::TerminalNode* CypherParser::PartialComparisonExpressionContext::SP() {
  return getToken(CypherParser::SP, 0);
}

tree::TerminalNode* CypherParser::PartialComparisonExpressionContext::NEQ() {
  return getToken(CypherParser::NEQ, 0);
}

tree::TerminalNode* CypherParser::PartialComparisonExpressionContext::LT() {
  return getToken(CypherParser::LT, 0);
}

tree::TerminalNode* CypherParser::PartialComparisonExpressionContext::GT() {
  return getToken(CypherParser::GT, 0);
}

tree::TerminalNode* CypherParser::PartialComparisonExpressionContext::LTE() {
  return getToken(CypherParser::LTE, 0);
}

tree::TerminalNode* CypherParser::PartialComparisonExpressionContext::GTE() {
  return getToken(CypherParser::GTE, 0);
}


size_t CypherParser::PartialComparisonExpressionContext::getRuleIndex() const {
  return CypherParser::RulePartialComparisonExpression;
}

antlrcpp::Any CypherParser::PartialComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPartialComparisonExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PartialComparisonExpressionContext* CypherParser::partialComparisonExpression() {
  PartialComparisonExpressionContext *_localctx = _tracker.createInstance<PartialComparisonExpressionContext>(_ctx, getState());
  enterRule(_localctx, 78, CypherParser::RulePartialComparisonExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(644);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CypherParser::EQUAL: {
        enterOuterAlt(_localctx, 1);
        setState(614);
        match(CypherParser::EQUAL);
        setState(616);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(615);
          match(CypherParser::SP);
        }
        setState(618);
        addOrSubtractExpression();
        break;
      }

      case CypherParser::NEQ: {
        enterOuterAlt(_localctx, 2);
        setState(619);
        match(CypherParser::NEQ);
        setState(621);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(620);
          match(CypherParser::SP);
        }
        setState(623);
        addOrSubtractExpression();
        break;
      }

      case CypherParser::LT: {
        enterOuterAlt(_localctx, 3);
        setState(624);
        match(CypherParser::LT);
        setState(626);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(625);
          match(CypherParser::SP);
        }
        setState(628);
        addOrSubtractExpression();
        break;
      }

      case CypherParser::GT: {
        enterOuterAlt(_localctx, 4);
        setState(629);
        match(CypherParser::GT);
        setState(631);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(630);
          match(CypherParser::SP);
        }
        setState(633);
        addOrSubtractExpression();
        break;
      }

      case CypherParser::LTE: {
        enterOuterAlt(_localctx, 5);
        setState(634);
        match(CypherParser::LTE);
        setState(636);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(635);
          match(CypherParser::SP);
        }
        setState(638);
        addOrSubtractExpression();
        break;
      }

      case CypherParser::GTE: {
        enterOuterAlt(_localctx, 6);
        setState(639);
        match(CypherParser::GTE);
        setState(641);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(640);
          match(CypherParser::SP);
        }
        setState(643);
        addOrSubtractExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOrSubtractExpressionContext ------------------------------------------------------------------

CypherParser::AddOrSubtractExpressionContext::AddOrSubtractExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::MultiplyDivideModuloExpressionContext *> CypherParser::AddOrSubtractExpressionContext::multiplyDivideModuloExpression() {
  return getRuleContexts<CypherParser::MultiplyDivideModuloExpressionContext>();
}

CypherParser::MultiplyDivideModuloExpressionContext* CypherParser::AddOrSubtractExpressionContext::multiplyDivideModuloExpression(size_t i) {
  return getRuleContext<CypherParser::MultiplyDivideModuloExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::AddOrSubtractExpressionContext::PLUS() {
  return getTokens(CypherParser::PLUS);
}

tree::TerminalNode* CypherParser::AddOrSubtractExpressionContext::PLUS(size_t i) {
  return getToken(CypherParser::PLUS, i);
}

std::vector<tree::TerminalNode *> CypherParser::AddOrSubtractExpressionContext::MINUS() {
  return getTokens(CypherParser::MINUS);
}

tree::TerminalNode* CypherParser::AddOrSubtractExpressionContext::MINUS(size_t i) {
  return getToken(CypherParser::MINUS, i);
}

std::vector<tree::TerminalNode *> CypherParser::AddOrSubtractExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::AddOrSubtractExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::AddOrSubtractExpressionContext::getRuleIndex() const {
  return CypherParser::RuleAddOrSubtractExpression;
}

antlrcpp::Any CypherParser::AddOrSubtractExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitAddOrSubtractExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::AddOrSubtractExpressionContext* CypherParser::addOrSubtractExpression() {
  AddOrSubtractExpressionContext *_localctx = _tracker.createInstance<AddOrSubtractExpressionContext>(_ctx, getState());
  enterRule(_localctx, 80, CypherParser::RuleAddOrSubtractExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(646);
    multiplyDivideModuloExpression();
    setState(665);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(663);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 122, _ctx)) {
        case 1: {
          setState(648);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(647);
            match(CypherParser::SP);
          }
          setState(650);
          match(CypherParser::PLUS);
          setState(652);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(651);
            match(CypherParser::SP);
          }
          setState(654);
          multiplyDivideModuloExpression();
          break;
        }

        case 2: {
          setState(656);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(655);
            match(CypherParser::SP);
          }
          setState(658);
          match(CypherParser::MINUS);
          setState(660);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(659);
            match(CypherParser::SP);
          }
          setState(662);
          multiplyDivideModuloExpression();
          break;
        }

        } 
      }
      setState(667);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplyDivideModuloExpressionContext ------------------------------------------------------------------

CypherParser::MultiplyDivideModuloExpressionContext::MultiplyDivideModuloExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::PowerOfExpressionContext *> CypherParser::MultiplyDivideModuloExpressionContext::powerOfExpression() {
  return getRuleContexts<CypherParser::PowerOfExpressionContext>();
}

CypherParser::PowerOfExpressionContext* CypherParser::MultiplyDivideModuloExpressionContext::powerOfExpression(size_t i) {
  return getRuleContext<CypherParser::PowerOfExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::MultiplyDivideModuloExpressionContext::STAR() {
  return getTokens(CypherParser::STAR);
}

tree::TerminalNode* CypherParser::MultiplyDivideModuloExpressionContext::STAR(size_t i) {
  return getToken(CypherParser::STAR, i);
}

std::vector<tree::TerminalNode *> CypherParser::MultiplyDivideModuloExpressionContext::SLASH() {
  return getTokens(CypherParser::SLASH);
}

tree::TerminalNode* CypherParser::MultiplyDivideModuloExpressionContext::SLASH(size_t i) {
  return getToken(CypherParser::SLASH, i);
}

std::vector<tree::TerminalNode *> CypherParser::MultiplyDivideModuloExpressionContext::PERCENT() {
  return getTokens(CypherParser::PERCENT);
}

tree::TerminalNode* CypherParser::MultiplyDivideModuloExpressionContext::PERCENT(size_t i) {
  return getToken(CypherParser::PERCENT, i);
}

std::vector<tree::TerminalNode *> CypherParser::MultiplyDivideModuloExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::MultiplyDivideModuloExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::MultiplyDivideModuloExpressionContext::getRuleIndex() const {
  return CypherParser::RuleMultiplyDivideModuloExpression;
}

antlrcpp::Any CypherParser::MultiplyDivideModuloExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitMultiplyDivideModuloExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::MultiplyDivideModuloExpressionContext* CypherParser::multiplyDivideModuloExpression() {
  MultiplyDivideModuloExpressionContext *_localctx = _tracker.createInstance<MultiplyDivideModuloExpressionContext>(_ctx, getState());
  enterRule(_localctx, 82, CypherParser::RuleMultiplyDivideModuloExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(668);
    powerOfExpression();
    setState(695);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(693);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx)) {
        case 1: {
          setState(670);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(669);
            match(CypherParser::SP);
          }
          setState(672);
          match(CypherParser::STAR);
          setState(674);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(673);
            match(CypherParser::SP);
          }
          setState(676);
          powerOfExpression();
          break;
        }

        case 2: {
          setState(678);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(677);
            match(CypherParser::SP);
          }
          setState(680);
          match(CypherParser::SLASH);
          setState(682);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(681);
            match(CypherParser::SP);
          }
          setState(684);
          powerOfExpression();
          break;
        }

        case 3: {
          setState(686);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(685);
            match(CypherParser::SP);
          }
          setState(688);
          match(CypherParser::PERCENT);
          setState(690);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(689);
            match(CypherParser::SP);
          }
          setState(692);
          powerOfExpression();
          break;
        }

        } 
      }
      setState(697);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PowerOfExpressionContext ------------------------------------------------------------------

CypherParser::PowerOfExpressionContext::PowerOfExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CypherParser::UnaryAddOrSubtractExpressionContext *> CypherParser::PowerOfExpressionContext::unaryAddOrSubtractExpression() {
  return getRuleContexts<CypherParser::UnaryAddOrSubtractExpressionContext>();
}

CypherParser::UnaryAddOrSubtractExpressionContext* CypherParser::PowerOfExpressionContext::unaryAddOrSubtractExpression(size_t i) {
  return getRuleContext<CypherParser::UnaryAddOrSubtractExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::PowerOfExpressionContext::CARET() {
  return getTokens(CypherParser::CARET);
}

tree::TerminalNode* CypherParser::PowerOfExpressionContext::CARET(size_t i) {
  return getToken(CypherParser::CARET, i);
}

std::vector<tree::TerminalNode *> CypherParser::PowerOfExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::PowerOfExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::PowerOfExpressionContext::getRuleIndex() const {
  return CypherParser::RulePowerOfExpression;
}

antlrcpp::Any CypherParser::PowerOfExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPowerOfExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PowerOfExpressionContext* CypherParser::powerOfExpression() {
  PowerOfExpressionContext *_localctx = _tracker.createInstance<PowerOfExpressionContext>(_ctx, getState());
  enterRule(_localctx, 84, CypherParser::RulePowerOfExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(698);
    unaryAddOrSubtractExpression();
    setState(709);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(700);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(699);
          match(CypherParser::SP);
        }
        setState(702);
        match(CypherParser::CARET);
        setState(704);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CypherParser::SP) {
          setState(703);
          match(CypherParser::SP);
        }
        setState(706);
        unaryAddOrSubtractExpression(); 
      }
      setState(711);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryAddOrSubtractExpressionContext ------------------------------------------------------------------

CypherParser::UnaryAddOrSubtractExpressionContext::UnaryAddOrSubtractExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::AtomContext* CypherParser::UnaryAddOrSubtractExpressionContext::atom() {
  return getRuleContext<CypherParser::AtomContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::UnaryAddOrSubtractExpressionContext::PLUS() {
  return getTokens(CypherParser::PLUS);
}

tree::TerminalNode* CypherParser::UnaryAddOrSubtractExpressionContext::PLUS(size_t i) {
  return getToken(CypherParser::PLUS, i);
}

std::vector<tree::TerminalNode *> CypherParser::UnaryAddOrSubtractExpressionContext::MINUS() {
  return getTokens(CypherParser::MINUS);
}

tree::TerminalNode* CypherParser::UnaryAddOrSubtractExpressionContext::MINUS(size_t i) {
  return getToken(CypherParser::MINUS, i);
}


size_t CypherParser::UnaryAddOrSubtractExpressionContext::getRuleIndex() const {
  return CypherParser::RuleUnaryAddOrSubtractExpression;
}

antlrcpp::Any CypherParser::UnaryAddOrSubtractExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitUnaryAddOrSubtractExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::UnaryAddOrSubtractExpressionContext* CypherParser::unaryAddOrSubtractExpression() {
  UnaryAddOrSubtractExpressionContext *_localctx = _tracker.createInstance<UnaryAddOrSubtractExpressionContext>(_ctx, getState());
  enterRule(_localctx, 86, CypherParser::RuleUnaryAddOrSubtractExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(715);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CypherParser::PLUS

    || _la == CypherParser::MINUS) {
      setState(712);
      _la = _input->LA(1);
      if (!(_la == CypherParser::PLUS

      || _la == CypherParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(717);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(718);
    atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

CypherParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::LiteralContext* CypherParser::AtomContext::literal() {
  return getRuleContext<CypherParser::LiteralContext>(0);
}

CypherParser::ParameterContext* CypherParser::AtomContext::parameter() {
  return getRuleContext<CypherParser::ParameterContext>(0);
}

CypherParser::FunctionInvocationContext* CypherParser::AtomContext::functionInvocation() {
  return getRuleContext<CypherParser::FunctionInvocationContext>(0);
}

CypherParser::VariableContext* CypherParser::AtomContext::variable() {
  return getRuleContext<CypherParser::VariableContext>(0);
}

tree::TerminalNode* CypherParser::AtomContext::LPAREN() {
  return getToken(CypherParser::LPAREN, 0);
}

CypherParser::ExpressionContext* CypherParser::AtomContext::expression() {
  return getRuleContext<CypherParser::ExpressionContext>(0);
}

tree::TerminalNode* CypherParser::AtomContext::RPAREN() {
  return getToken(CypherParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> CypherParser::AtomContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::AtomContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::AtomContext::getRuleIndex() const {
  return CypherParser::RuleAtom;
}

antlrcpp::Any CypherParser::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::AtomContext* CypherParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 88, CypherParser::RuleAtom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(734);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(720);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(721);
      parameter();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(722);
      functionInvocation();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(723);
      variable();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(724);
      match(CypherParser::LPAREN);
      setState(726);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(725);
        match(CypherParser::SP);
      }
      setState(728);
      expression();
      setState(730);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(729);
        match(CypherParser::SP);
      }
      setState(732);
      match(CypherParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionInvocationContext ------------------------------------------------------------------

CypherParser::FunctionInvocationContext::FunctionInvocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::FunctionNameContext* CypherParser::FunctionInvocationContext::functionName() {
  return getRuleContext<CypherParser::FunctionNameContext>(0);
}

tree::TerminalNode* CypherParser::FunctionInvocationContext::LPAREN() {
  return getToken(CypherParser::LPAREN, 0);
}

tree::TerminalNode* CypherParser::FunctionInvocationContext::RPAREN() {
  return getToken(CypherParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> CypherParser::FunctionInvocationContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::FunctionInvocationContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

tree::TerminalNode* CypherParser::FunctionInvocationContext::DISTINCT() {
  return getToken(CypherParser::DISTINCT, 0);
}

std::vector<CypherParser::ExpressionContext *> CypherParser::FunctionInvocationContext::expression() {
  return getRuleContexts<CypherParser::ExpressionContext>();
}

CypherParser::ExpressionContext* CypherParser::FunctionInvocationContext::expression(size_t i) {
  return getRuleContext<CypherParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::FunctionInvocationContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::FunctionInvocationContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}


size_t CypherParser::FunctionInvocationContext::getRuleIndex() const {
  return CypherParser::RuleFunctionInvocation;
}

antlrcpp::Any CypherParser::FunctionInvocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitFunctionInvocation(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::FunctionInvocationContext* CypherParser::functionInvocation() {
  FunctionInvocationContext *_localctx = _tracker.createInstance<FunctionInvocationContext>(_ctx, getState());
  enterRule(_localctx, 90, CypherParser::RuleFunctionInvocation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(736);
    functionName();
    setState(738);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(737);
      match(CypherParser::SP);
    }
    setState(740);
    match(CypherParser::LPAREN);
    setState(742);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx)) {
    case 1: {
      setState(741);
      match(CypherParser::SP);
      break;
    }

    }
    setState(748);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::DISTINCT) {
      setState(744);
      match(CypherParser::DISTINCT);
      setState(746);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx)) {
      case 1: {
        setState(745);
        match(CypherParser::SP);
        break;
      }

      }
    }
    setState(764);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CypherParser::NOT)
      | (1ULL << CypherParser::NULL_)
      | (1ULL << CypherParser::TRUE_)
      | (1ULL << CypherParser::FALSE_)
      | (1ULL << CypherParser::PLUS)
      | (1ULL << CypherParser::MINUS)
      | (1ULL << CypherParser::DOLLAR)
      | (1ULL << CypherParser::LPAREN)
      | (1ULL << CypherParser::LBRACE)
      | (1ULL << CypherParser::LBRACK)
      | (1ULL << CypherParser::BACKTICK)
      | (1ULL << CypherParser::STRING)
      | (1ULL << CypherParser::INTEGER_LITERAL)
      | (1ULL << CypherParser::DOUBLE_LITERAL)
      | (1ULL << CypherParser::IDENTIFIER))) != 0)) {
      setState(750);
      expression();
      setState(761);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(752);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(751);
            match(CypherParser::SP);
          }
          setState(754);
          match(CypherParser::COMMA);
          setState(756);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(755);
            match(CypherParser::SP);
          }
          setState(758);
          expression(); 
        }
        setState(763);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx);
      }
    }
    setState(767);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(766);
      match(CypherParser::SP);
    }
    setState(769);
    match(CypherParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

CypherParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SymbolicNameContext* CypherParser::FunctionNameContext::symbolicName() {
  return getRuleContext<CypherParser::SymbolicNameContext>(0);
}


size_t CypherParser::FunctionNameContext::getRuleIndex() const {
  return CypherParser::RuleFunctionName;
}

antlrcpp::Any CypherParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::FunctionNameContext* CypherParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 92, CypherParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(771);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyExpressionContext ------------------------------------------------------------------

CypherParser::PropertyExpressionContext::PropertyExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::AtomContext* CypherParser::PropertyExpressionContext::atom() {
  return getRuleContext<CypherParser::AtomContext>(0);
}

std::vector<tree::TerminalNode *> CypherParser::PropertyExpressionContext::DOT() {
  return getTokens(CypherParser::DOT);
}

tree::TerminalNode* CypherParser::PropertyExpressionContext::DOT(size_t i) {
  return getToken(CypherParser::DOT, i);
}

std::vector<CypherParser::PropertyKeyNameContext *> CypherParser::PropertyExpressionContext::propertyKeyName() {
  return getRuleContexts<CypherParser::PropertyKeyNameContext>();
}

CypherParser::PropertyKeyNameContext* CypherParser::PropertyExpressionContext::propertyKeyName(size_t i) {
  return getRuleContext<CypherParser::PropertyKeyNameContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::PropertyExpressionContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::PropertyExpressionContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}


size_t CypherParser::PropertyExpressionContext::getRuleIndex() const {
  return CypherParser::RulePropertyExpression;
}

antlrcpp::Any CypherParser::PropertyExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPropertyExpression(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PropertyExpressionContext* CypherParser::propertyExpression() {
  PropertyExpressionContext *_localctx = _tracker.createInstance<PropertyExpressionContext>(_ctx, getState());
  enterRule(_localctx, 94, CypherParser::RulePropertyExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(773);
    atom();
    setState(782); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(775);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == CypherParser::SP) {
                setState(774);
                match(CypherParser::SP);
              }
              setState(777);
              match(CypherParser::DOT);
              setState(779);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == CypherParser::SP) {
                setState(778);
                match(CypherParser::SP);
              }
              setState(781);
              propertyKeyName();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(784); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyKeyNameContext ------------------------------------------------------------------

CypherParser::PropertyKeyNameContext::PropertyKeyNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SchemaNameContext* CypherParser::PropertyKeyNameContext::schemaName() {
  return getRuleContext<CypherParser::SchemaNameContext>(0);
}


size_t CypherParser::PropertyKeyNameContext::getRuleIndex() const {
  return CypherParser::RulePropertyKeyName;
}

antlrcpp::Any CypherParser::PropertyKeyNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitPropertyKeyName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::PropertyKeyNameContext* CypherParser::propertyKeyName() {
  PropertyKeyNameContext *_localctx = _tracker.createInstance<PropertyKeyNameContext>(_ctx, getState());
  enterRule(_localctx, 96, CypherParser::RulePropertyKeyName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(786);
    schemaName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelNameContext ------------------------------------------------------------------

CypherParser::LabelNameContext::LabelNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SchemaNameContext* CypherParser::LabelNameContext::schemaName() {
  return getRuleContext<CypherParser::SchemaNameContext>(0);
}


size_t CypherParser::LabelNameContext::getRuleIndex() const {
  return CypherParser::RuleLabelName;
}

antlrcpp::Any CypherParser::LabelNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitLabelName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::LabelNameContext* CypherParser::labelName() {
  LabelNameContext *_localctx = _tracker.createInstance<LabelNameContext>(_ctx, getState());
  enterRule(_localctx, 98, CypherParser::RuleLabelName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(788);
    schemaName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelTypeNameContext ------------------------------------------------------------------

CypherParser::RelTypeNameContext::RelTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SchemaNameContext* CypherParser::RelTypeNameContext::schemaName() {
  return getRuleContext<CypherParser::SchemaNameContext>(0);
}


size_t CypherParser::RelTypeNameContext::getRuleIndex() const {
  return CypherParser::RuleRelTypeName;
}

antlrcpp::Any CypherParser::RelTypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitRelTypeName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::RelTypeNameContext* CypherParser::relTypeName() {
  RelTypeNameContext *_localctx = _tracker.createInstance<RelTypeNameContext>(_ctx, getState());
  enterRule(_localctx, 100, CypherParser::RuleRelTypeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(790);
    schemaName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SchemaNameContext ------------------------------------------------------------------

CypherParser::SchemaNameContext::SchemaNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SymbolicNameContext* CypherParser::SchemaNameContext::symbolicName() {
  return getRuleContext<CypherParser::SymbolicNameContext>(0);
}


size_t CypherParser::SchemaNameContext::getRuleIndex() const {
  return CypherParser::RuleSchemaName;
}

antlrcpp::Any CypherParser::SchemaNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSchemaName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SchemaNameContext* CypherParser::schemaName() {
  SchemaNameContext *_localctx = _tracker.createInstance<SchemaNameContext>(_ctx, getState());
  enterRule(_localctx, 102, CypherParser::RuleSchemaName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(792);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

CypherParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::SymbolicNameContext* CypherParser::VariableContext::symbolicName() {
  return getRuleContext<CypherParser::SymbolicNameContext>(0);
}


size_t CypherParser::VariableContext::getRuleIndex() const {
  return CypherParser::RuleVariable;
}

antlrcpp::Any CypherParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::VariableContext* CypherParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 104, CypherParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(794);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolicNameContext ------------------------------------------------------------------

CypherParser::SymbolicNameContext::SymbolicNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::UnescapedSymbolicNameContext* CypherParser::SymbolicNameContext::unescapedSymbolicName() {
  return getRuleContext<CypherParser::UnescapedSymbolicNameContext>(0);
}

CypherParser::EscapedSymbolicNameContext* CypherParser::SymbolicNameContext::escapedSymbolicName() {
  return getRuleContext<CypherParser::EscapedSymbolicNameContext>(0);
}


size_t CypherParser::SymbolicNameContext::getRuleIndex() const {
  return CypherParser::RuleSymbolicName;
}

antlrcpp::Any CypherParser::SymbolicNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitSymbolicName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::SymbolicNameContext* CypherParser::symbolicName() {
  SymbolicNameContext *_localctx = _tracker.createInstance<SymbolicNameContext>(_ctx, getState());
  enterRule(_localctx, 106, CypherParser::RuleSymbolicName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(798);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CypherParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(796);
        unescapedSymbolicName();
        break;
      }

      case CypherParser::BACKTICK: {
        enterOuterAlt(_localctx, 2);
        setState(797);
        escapedSymbolicName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnescapedSymbolicNameContext ------------------------------------------------------------------

CypherParser::UnescapedSymbolicNameContext::UnescapedSymbolicNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::UnescapedSymbolicNameContext::IDENTIFIER() {
  return getToken(CypherParser::IDENTIFIER, 0);
}


size_t CypherParser::UnescapedSymbolicNameContext::getRuleIndex() const {
  return CypherParser::RuleUnescapedSymbolicName;
}

antlrcpp::Any CypherParser::UnescapedSymbolicNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitUnescapedSymbolicName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::UnescapedSymbolicNameContext* CypherParser::unescapedSymbolicName() {
  UnescapedSymbolicNameContext *_localctx = _tracker.createInstance<UnescapedSymbolicNameContext>(_ctx, getState());
  enterRule(_localctx, 108, CypherParser::RuleUnescapedSymbolicName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(800);
    match(CypherParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EscapedSymbolicNameContext ------------------------------------------------------------------

CypherParser::EscapedSymbolicNameContext::EscapedSymbolicNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CypherParser::EscapedSymbolicNameContext::BACKTICK() {
  return getTokens(CypherParser::BACKTICK);
}

tree::TerminalNode* CypherParser::EscapedSymbolicNameContext::BACKTICK(size_t i) {
  return getToken(CypherParser::BACKTICK, i);
}


size_t CypherParser::EscapedSymbolicNameContext::getRuleIndex() const {
  return CypherParser::RuleEscapedSymbolicName;
}

antlrcpp::Any CypherParser::EscapedSymbolicNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitEscapedSymbolicName(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::EscapedSymbolicNameContext* CypherParser::escapedSymbolicName() {
  EscapedSymbolicNameContext *_localctx = _tracker.createInstance<EscapedSymbolicNameContext>(_ctx, getState());
  enterRule(_localctx, 110, CypherParser::RuleEscapedSymbolicName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(802);
    match(CypherParser::BACKTICK);
    setState(808);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(806);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CypherParser::T__0:
          case CypherParser::MATCH:
          case CypherParser::CREATE:
          case CypherParser::DELETE:
          case CypherParser::SET:
          case CypherParser::RETURN:
          case CypherParser::WHERE:
          case CypherParser::AND:
          case CypherParser::OR:
          case CypherParser::XOR:
          case CypherParser::NOT:
          case CypherParser::DISTINCT:
          case CypherParser::LIMIT:
          case CypherParser::SKIP:
          case CypherParser::ORDER:
          case CypherParser::BY:
          case CypherParser::ASC:
          case CypherParser::DESC:
          case CypherParser::NULL_:
          case CypherParser::TRUE_:
          case CypherParser::FALSE_:
          case CypherParser::IN:
          case CypherParser::IS:
          case CypherParser::AS:
          case CypherParser::DETACH:
          case CypherParser::EQUAL:
          case CypherParser::NEQ:
          case CypherParser::LT:
          case CypherParser::GT:
          case CypherParser::LTE:
          case CypherParser::GTE:
          case CypherParser::PLUS:
          case CypherParser::MINUS:
          case CypherParser::SLASH:
          case CypherParser::PERCENT:
          case CypherParser::CARET:
          case CypherParser::PIPE:
          case CypherParser::AMP:
          case CypherParser::DOT:
          case CypherParser::DASH:
          case CypherParser::COMMA:
          case CypherParser::COLON:
          case CypherParser::SEMI:
          case CypherParser::DOLLAR:
          case CypherParser::QUESTION:
          case CypherParser::AT:
          case CypherParser::TILDE:
          case CypherParser::BANG:
          case CypherParser::LPAREN:
          case CypherParser::RPAREN:
          case CypherParser::LBRACE:
          case CypherParser::RBRACE:
          case CypherParser::LBRACK:
          case CypherParser::RBRACK:
          case CypherParser::STRING:
          case CypherParser::INTEGER_LITERAL:
          case CypherParser::DOUBLE_LITERAL:
          case CypherParser::IDENTIFIER:
          case CypherParser::SP:
          case CypherParser::LINE_COMMENT:
          case CypherParser::BLOCK_COMMENT:
          case CypherParser::STAR: {
            setState(803);
            _la = _input->LA(1);
            if (_la == 0 || _la == Token::EOF || (_la == CypherParser::BACKTICK)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
            break;
          }

          case CypherParser::BACKTICK: {
            setState(804);
            match(CypherParser::BACKTICK);
            setState(805);
            match(CypherParser::BACKTICK);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(810);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx);
    }
    setState(811);
    match(CypherParser::BACKTICK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

CypherParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CypherParser::NumberLiteralContext* CypherParser::LiteralContext::numberLiteral() {
  return getRuleContext<CypherParser::NumberLiteralContext>(0);
}

CypherParser::StringLiteralContext* CypherParser::LiteralContext::stringLiteral() {
  return getRuleContext<CypherParser::StringLiteralContext>(0);
}

CypherParser::BooleanLiteralContext* CypherParser::LiteralContext::booleanLiteral() {
  return getRuleContext<CypherParser::BooleanLiteralContext>(0);
}

tree::TerminalNode* CypherParser::LiteralContext::NULL_() {
  return getToken(CypherParser::NULL_, 0);
}

CypherParser::MapLiteralContext* CypherParser::LiteralContext::mapLiteral() {
  return getRuleContext<CypherParser::MapLiteralContext>(0);
}

CypherParser::ListLiteralContext* CypherParser::LiteralContext::listLiteral() {
  return getRuleContext<CypherParser::ListLiteralContext>(0);
}


size_t CypherParser::LiteralContext::getRuleIndex() const {
  return CypherParser::RuleLiteral;
}

antlrcpp::Any CypherParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::LiteralContext* CypherParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 112, CypherParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(819);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CypherParser::INTEGER_LITERAL:
      case CypherParser::DOUBLE_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(813);
        numberLiteral();
        break;
      }

      case CypherParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(814);
        stringLiteral();
        break;
      }

      case CypherParser::TRUE_:
      case CypherParser::FALSE_: {
        enterOuterAlt(_localctx, 3);
        setState(815);
        booleanLiteral();
        break;
      }

      case CypherParser::NULL_: {
        enterOuterAlt(_localctx, 4);
        setState(816);
        match(CypherParser::NULL_);
        break;
      }

      case CypherParser::LBRACE: {
        enterOuterAlt(_localctx, 5);
        setState(817);
        mapLiteral();
        break;
      }

      case CypherParser::LBRACK: {
        enterOuterAlt(_localctx, 6);
        setState(818);
        listLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberLiteralContext ------------------------------------------------------------------

CypherParser::NumberLiteralContext::NumberLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::NumberLiteralContext::DOUBLE_LITERAL() {
  return getToken(CypherParser::DOUBLE_LITERAL, 0);
}

tree::TerminalNode* CypherParser::NumberLiteralContext::INTEGER_LITERAL() {
  return getToken(CypherParser::INTEGER_LITERAL, 0);
}


size_t CypherParser::NumberLiteralContext::getRuleIndex() const {
  return CypherParser::RuleNumberLiteral;
}

antlrcpp::Any CypherParser::NumberLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitNumberLiteral(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::NumberLiteralContext* CypherParser::numberLiteral() {
  NumberLiteralContext *_localctx = _tracker.createInstance<NumberLiteralContext>(_ctx, getState());
  enterRule(_localctx, 114, CypherParser::RuleNumberLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(821);
    _la = _input->LA(1);
    if (!(_la == CypherParser::INTEGER_LITERAL

    || _la == CypherParser::DOUBLE_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringLiteralContext ------------------------------------------------------------------

CypherParser::StringLiteralContext::StringLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::StringLiteralContext::STRING() {
  return getToken(CypherParser::STRING, 0);
}


size_t CypherParser::StringLiteralContext::getRuleIndex() const {
  return CypherParser::RuleStringLiteral;
}

antlrcpp::Any CypherParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::StringLiteralContext* CypherParser::stringLiteral() {
  StringLiteralContext *_localctx = _tracker.createInstance<StringLiteralContext>(_ctx, getState());
  enterRule(_localctx, 116, CypherParser::RuleStringLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(823);
    match(CypherParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanLiteralContext ------------------------------------------------------------------

CypherParser::BooleanLiteralContext::BooleanLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::BooleanLiteralContext::TRUE_() {
  return getToken(CypherParser::TRUE_, 0);
}

tree::TerminalNode* CypherParser::BooleanLiteralContext::FALSE_() {
  return getToken(CypherParser::FALSE_, 0);
}


size_t CypherParser::BooleanLiteralContext::getRuleIndex() const {
  return CypherParser::RuleBooleanLiteral;
}

antlrcpp::Any CypherParser::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::BooleanLiteralContext* CypherParser::booleanLiteral() {
  BooleanLiteralContext *_localctx = _tracker.createInstance<BooleanLiteralContext>(_ctx, getState());
  enterRule(_localctx, 118, CypherParser::RuleBooleanLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(825);
    _la = _input->LA(1);
    if (!(_la == CypherParser::TRUE_

    || _la == CypherParser::FALSE_)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapLiteralContext ------------------------------------------------------------------

CypherParser::MapLiteralContext::MapLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::MapLiteralContext::LBRACE() {
  return getToken(CypherParser::LBRACE, 0);
}

tree::TerminalNode* CypherParser::MapLiteralContext::RBRACE() {
  return getToken(CypherParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> CypherParser::MapLiteralContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::MapLiteralContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

std::vector<CypherParser::PropertyKeyNameContext *> CypherParser::MapLiteralContext::propertyKeyName() {
  return getRuleContexts<CypherParser::PropertyKeyNameContext>();
}

CypherParser::PropertyKeyNameContext* CypherParser::MapLiteralContext::propertyKeyName(size_t i) {
  return getRuleContext<CypherParser::PropertyKeyNameContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::MapLiteralContext::COLON() {
  return getTokens(CypherParser::COLON);
}

tree::TerminalNode* CypherParser::MapLiteralContext::COLON(size_t i) {
  return getToken(CypherParser::COLON, i);
}

std::vector<CypherParser::ExpressionContext *> CypherParser::MapLiteralContext::expression() {
  return getRuleContexts<CypherParser::ExpressionContext>();
}

CypherParser::ExpressionContext* CypherParser::MapLiteralContext::expression(size_t i) {
  return getRuleContext<CypherParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::MapLiteralContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::MapLiteralContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}


size_t CypherParser::MapLiteralContext::getRuleIndex() const {
  return CypherParser::RuleMapLiteral;
}

antlrcpp::Any CypherParser::MapLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitMapLiteral(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::MapLiteralContext* CypherParser::mapLiteral() {
  MapLiteralContext *_localctx = _tracker.createInstance<MapLiteralContext>(_ctx, getState());
  enterRule(_localctx, 120, CypherParser::RuleMapLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(827);
    match(CypherParser::LBRACE);
    setState(829);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 155, _ctx)) {
    case 1: {
      setState(828);
      match(CypherParser::SP);
      break;
    }

    }
    setState(862);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::BACKTICK

    || _la == CypherParser::IDENTIFIER) {
      setState(831);
      propertyKeyName();
      setState(833);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(832);
        match(CypherParser::SP);
      }
      setState(835);
      match(CypherParser::COLON);
      setState(837);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CypherParser::SP) {
        setState(836);
        match(CypherParser::SP);
      }
      setState(839);
      expression();
      setState(859);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(841);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(840);
            match(CypherParser::SP);
          }
          setState(843);
          match(CypherParser::COMMA);
          setState(845);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(844);
            match(CypherParser::SP);
          }
          setState(847);
          propertyKeyName();
          setState(849);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(848);
            match(CypherParser::SP);
          }
          setState(851);
          match(CypherParser::COLON);
          setState(853);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(852);
            match(CypherParser::SP);
          }
          setState(855);
          expression(); 
        }
        setState(861);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
      }
    }
    setState(865);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(864);
      match(CypherParser::SP);
    }
    setState(867);
    match(CypherParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListLiteralContext ------------------------------------------------------------------

CypherParser::ListLiteralContext::ListLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::ListLiteralContext::LBRACK() {
  return getToken(CypherParser::LBRACK, 0);
}

tree::TerminalNode* CypherParser::ListLiteralContext::RBRACK() {
  return getToken(CypherParser::RBRACK, 0);
}

std::vector<tree::TerminalNode *> CypherParser::ListLiteralContext::SP() {
  return getTokens(CypherParser::SP);
}

tree::TerminalNode* CypherParser::ListLiteralContext::SP(size_t i) {
  return getToken(CypherParser::SP, i);
}

std::vector<CypherParser::ExpressionContext *> CypherParser::ListLiteralContext::expression() {
  return getRuleContexts<CypherParser::ExpressionContext>();
}

CypherParser::ExpressionContext* CypherParser::ListLiteralContext::expression(size_t i) {
  return getRuleContext<CypherParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CypherParser::ListLiteralContext::COMMA() {
  return getTokens(CypherParser::COMMA);
}

tree::TerminalNode* CypherParser::ListLiteralContext::COMMA(size_t i) {
  return getToken(CypherParser::COMMA, i);
}


size_t CypherParser::ListLiteralContext::getRuleIndex() const {
  return CypherParser::RuleListLiteral;
}

antlrcpp::Any CypherParser::ListLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitListLiteral(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ListLiteralContext* CypherParser::listLiteral() {
  ListLiteralContext *_localctx = _tracker.createInstance<ListLiteralContext>(_ctx, getState());
  enterRule(_localctx, 122, CypherParser::RuleListLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(869);
    match(CypherParser::LBRACK);
    setState(871);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx)) {
    case 1: {
      setState(870);
      match(CypherParser::SP);
      break;
    }

    }
    setState(887);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CypherParser::NOT)
      | (1ULL << CypherParser::NULL_)
      | (1ULL << CypherParser::TRUE_)
      | (1ULL << CypherParser::FALSE_)
      | (1ULL << CypherParser::PLUS)
      | (1ULL << CypherParser::MINUS)
      | (1ULL << CypherParser::DOLLAR)
      | (1ULL << CypherParser::LPAREN)
      | (1ULL << CypherParser::LBRACE)
      | (1ULL << CypherParser::LBRACK)
      | (1ULL << CypherParser::BACKTICK)
      | (1ULL << CypherParser::STRING)
      | (1ULL << CypherParser::INTEGER_LITERAL)
      | (1ULL << CypherParser::DOUBLE_LITERAL)
      | (1ULL << CypherParser::IDENTIFIER))) != 0)) {
      setState(873);
      expression();
      setState(884);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(875);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(874);
            match(CypherParser::SP);
          }
          setState(877);
          match(CypherParser::COMMA);
          setState(879);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CypherParser::SP) {
            setState(878);
            match(CypherParser::SP);
          }
          setState(881);
          expression(); 
        }
        setState(886);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
      }
    }
    setState(890);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CypherParser::SP) {
      setState(889);
      match(CypherParser::SP);
    }
    setState(892);
    match(CypherParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

CypherParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CypherParser::ParameterContext::DOLLAR() {
  return getToken(CypherParser::DOLLAR, 0);
}

CypherParser::SymbolicNameContext* CypherParser::ParameterContext::symbolicName() {
  return getRuleContext<CypherParser::SymbolicNameContext>(0);
}


size_t CypherParser::ParameterContext::getRuleIndex() const {
  return CypherParser::RuleParameter;
}

antlrcpp::Any CypherParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CypherVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

CypherParser::ParameterContext* CypherParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 124, CypherParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(894);
    match(CypherParser::DOLLAR);
    setState(895);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> CypherParser::_decisionToDFA;
atn::PredictionContextCache CypherParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CypherParser::_atn;
std::vector<uint16_t> CypherParser::_serializedATN;

std::vector<std::string> CypherParser::_ruleNames = {
  "cypher", "query", "singleQuery", "singlePartQuery", "readingClause", 
  "matchClause", "updatingClause", "createClause", "deleteClause", "setClause", 
  "setItem", "returnClause", "returnBody", "returnItems", "returnItem", 
  "whereClause", "order", "sortItem", "skip", "limit", "pattern", "patternPart", 
  "anonymousPatternPart", "patternElement", "patternElementChain", "nodePattern", 
  "relationshipPattern", "arrowHead", "relationshipDetail", "properties", 
  "nodeLabels", "nodeLabel", "relationshipTypes", "expression", "orExpression", 
  "xorExpression", "andExpression", "notExpression", "comparisonExpression", 
  "partialComparisonExpression", "addOrSubtractExpression", "multiplyDivideModuloExpression", 
  "powerOfExpression", "unaryAddOrSubtractExpression", "atom", "functionInvocation", 
  "functionName", "propertyExpression", "propertyKeyName", "labelName", 
  "relTypeName", "schemaName", "variable", "symbolicName", "unescapedSymbolicName", 
  "escapedSymbolicName", "literal", "numberLiteral", "stringLiteral", "booleanLiteral", 
  "mapLiteral", "listLiteral", "parameter"
};

std::vector<std::string> CypherParser::_literalNames = {
  "", "'*'", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "'='", "'<>'", "'<'", "'>'", "'<='", 
  "'>='", "'+'", "", "'/'", "'%'", "'^'", "'|'", "'&'", "'.'", "", "','", 
  "':'", "';'", "'$'", "'?'", "'@'", "'~'", "'!'", "'('", "')'", "'{'", 
  "'}'", "'['", "']'", "'`'"
};

std::vector<std::string> CypherParser::_symbolicNames = {
  "", "", "MATCH", "CREATE", "DELETE", "SET", "RETURN", "WHERE", "AND", 
  "OR", "XOR", "NOT", "DISTINCT", "LIMIT", "SKIP", "ORDER", "BY", "ASC", 
  "DESC", "NULL_", "TRUE_", "FALSE_", "IN", "IS", "AS", "DETACH", "EQUAL", 
  "NEQ", "LT", "GT", "LTE", "GTE", "PLUS", "MINUS", "SLASH", "PERCENT", 
  "CARET", "PIPE", "AMP", "DOT", "DASH", "COMMA", "COLON", "SEMI", "DOLLAR", 
  "QUESTION", "AT", "TILDE", "BANG", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
  "LBRACK", "RBRACK", "BACKTICK", "STRING", "INTEGER_LITERAL", "DOUBLE_LITERAL", 
  "IDENTIFIER", "SP", "LINE_COMMENT", "BLOCK_COMMENT", "STAR"
};

dfa::Vocabulary CypherParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CypherParser::_tokenNames;

CypherParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x41, 0x384, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x3, 0x2, 0x5, 0x2, 0x82, 0xa, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x8d, 0xa, 0x5, 0x7, 0x5, 0x8f, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x92, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x97, 0xa, 0x5, 0x7, 0x5, 0x99, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x9c, 
    0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xa0, 0xa, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0xa3, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xa6, 0xb, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0xa9, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0xac, 0xa, 0x5, 0x5, 0x5, 0xae, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xb4, 0xa, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xb8, 0xa, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0xbb, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xc0, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xc4, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x5, 0xa, 0xc9, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xcd, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd1, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0xd5, 0xa, 0xa, 0x3, 0xa, 0x7, 0xa, 0xd8, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0xdb, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xdf, 0xa, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xe3, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xe7, 0xa, 0xb, 0x3, 0xb, 0x7, 0xb, 0xea, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0xed, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xf1, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0xf5, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0xfb, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xff, 
    0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x105, 0xa, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x109, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0x10d, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x110, 0xa, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x117, 0xa, 0xe, 
    0x3, 0xe, 0x5, 0xe, 0x11a, 0xa, 0xe, 0x3, 0xe, 0x5, 0xe, 0x11d, 0xa, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0x120, 0xa, 0xe, 0x3, 0xe, 0x5, 0xe, 0x123, 
    0xa, 0xe, 0x3, 0xe, 0x5, 0xe, 0x126, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x12b, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x12f, 
    0xa, 0xf, 0x3, 0xf, 0x7, 0xf, 0x132, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x135, 
    0xb, 0xf, 0x5, 0xf, 0x137, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x13b, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x13f, 0xa, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0x142, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x146, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x150, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x5, 0x12, 0x154, 0xa, 0x12, 0x3, 0x12, 0x7, 0x12, 0x157, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x15a, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0x15e, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x162, 
    0xa, 0x13, 0x3, 0x13, 0x5, 0x13, 0x165, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0x169, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0x16f, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x5, 0x16, 0x175, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x179, 
    0xa, 0x16, 0x3, 0x16, 0x7, 0x16, 0x17c, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
    0x17f, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x183, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x187, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x18c, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x192, 0xa, 0x19, 0x3, 0x19, 0x7, 0x19, 0x195, 
    0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x198, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x19c, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x1a2, 0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1a5, 0xa, 0x1b, 
    0x3, 0x1b, 0x5, 0x1b, 0x1a8, 0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1ab, 
    0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1ae, 0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 
    0x1b1, 0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1b4, 0xa, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1ba, 0xa, 0x1c, 0x3, 0x1c, 
    0x5, 0x1c, 0x1bd, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1c0, 0xa, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1c4, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x1c9, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 
    0x1cd, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1d0, 0xa, 0x1c, 0x3, 0x1c, 
    0x5, 0x1c, 0x1d3, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x5, 0x1c, 0x1d9, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1dc, 0xa, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x1df, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1e2, 
    0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 
    0x1d, 0x1e9, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1ed, 0xa, 
    0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1f0, 0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
    0x1f3, 0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1f6, 0xa, 0x1e, 0x3, 0x1e, 
    0x5, 0x1e, 0x1f9, 0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1fc, 0xa, 0x1e, 
    0x3, 0x1e, 0x5, 0x1e, 0x1ff, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x6, 0x20, 0x206, 0xa, 0x20, 0xd, 0x20, 0xe, 0x20, 
    0x207, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x20c, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x212, 0xa, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x5, 0x22, 0x216, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 
    0x21a, 0xa, 0x22, 0x3, 0x22, 0x5, 0x22, 0x21d, 0xa, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x220, 0xa, 0x22, 0x3, 0x22, 0x7, 0x22, 0x223, 0xa, 0x22, 
    0xc, 0x22, 0xe, 0x22, 0x226, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x22c, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x230, 0xa, 0x24, 0x3, 0x24, 0x7, 0x24, 0x233, 0xa, 0x24, 0xc, 0x24, 
    0xe, 0x24, 0x236, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x23a, 
    0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x23e, 0xa, 0x25, 0x3, 0x25, 
    0x7, 0x25, 0x241, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x244, 0xb, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x248, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x5, 0x26, 0x24c, 0xa, 0x26, 0x3, 0x26, 0x7, 0x26, 0x24f, 0xa, 0x26, 
    0xc, 0x26, 0xe, 0x26, 0x252, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x256, 0xa, 0x27, 0x7, 0x27, 0x258, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 
    0x25b, 0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x261, 0xa, 0x28, 0x3, 0x28, 0x7, 0x28, 0x264, 0xa, 0x28, 0xc, 0x28, 
    0xe, 0x28, 0x267, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x26b, 
    0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x270, 0xa, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x275, 0xa, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x27a, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x5, 0x29, 0x27f, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x5, 0x29, 0x284, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x287, 0xa, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x28b, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x5, 0x2a, 0x28f, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x293, 
    0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x297, 0xa, 0x2a, 0x3, 0x2a, 
    0x7, 0x2a, 0x29a, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x29d, 0xb, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x2a1, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x5, 0x2b, 0x2a5, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x2a9, 
    0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x2ad, 0xa, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x5, 0x2b, 0x2b1, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 
    0x2b5, 0xa, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x2b8, 0xa, 0x2b, 0xc, 0x2b, 
    0xe, 0x2b, 0x2bb, 0xb, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2bf, 
    0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2c3, 0xa, 0x2c, 0x3, 0x2c, 
    0x7, 0x2c, 0x2c6, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x2c9, 0xb, 0x2c, 
    0x3, 0x2d, 0x7, 0x2d, 0x2cc, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x2cf, 
    0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x2d9, 0xa, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x2dd, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
    0x2e1, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x2e5, 0xa, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x2e9, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x2ed, 0xa, 0x2f, 0x5, 0x2f, 0x2ef, 0xa, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x5, 0x2f, 0x2f3, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 
    0x2f7, 0xa, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x2fa, 0xa, 0x2f, 0xc, 0x2f, 
    0xe, 0x2f, 0x2fd, 0xb, 0x2f, 0x5, 0x2f, 0x2ff, 0xa, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x302, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x30a, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x5, 0x31, 0x30e, 0xa, 0x31, 0x3, 0x31, 0x6, 0x31, 0x311, 0xa, 0x31, 
    0xd, 0x31, 0xe, 0x31, 0x312, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x37, 0x3, 0x37, 0x5, 0x37, 0x321, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x329, 0xa, 0x39, 
    0xc, 0x39, 0xe, 0x39, 0x32c, 0xb, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x336, 
    0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 
    0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x340, 0xa, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x344, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 
    0x348, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x34c, 0xa, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x350, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x5, 0x3e, 0x354, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x358, 
    0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x35c, 0xa, 0x3e, 0xc, 0x3e, 
    0xe, 0x3e, 0x35f, 0xb, 0x3e, 0x5, 0x3e, 0x361, 0xa, 0x3e, 0x3, 0x3e, 
    0x5, 0x3e, 0x364, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 
    0x5, 0x3f, 0x36a, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x36e, 
    0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x372, 0xa, 0x3f, 0x3, 0x3f, 
    0x7, 0x3f, 0x375, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x378, 0xb, 0x3f, 
    0x5, 0x3f, 0x37a, 0xa, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x37d, 0xa, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x2, 
    0x2, 0x41, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
    0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
    0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 
    0x78, 0x7a, 0x7c, 0x7e, 0x2, 0x6, 0x3, 0x2, 0x22, 0x23, 0x3, 0x2, 0x39, 
    0x39, 0x3, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x16, 0x17, 0x2, 0x3ff, 0x2, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x86, 0x3, 0x2, 0x2, 0x2, 0x6, 0x88, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xad, 0x3, 0x2, 0x2, 0x2, 0xa, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0x12, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x14, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x108, 0x3, 0x2, 0x2, 0x2, 0x18, 0x10a, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x114, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x138, 0x3, 0x2, 0x2, 0x2, 0x20, 0x143, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x149, 0x3, 0x2, 0x2, 0x2, 0x24, 0x15b, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x166, 0x3, 0x2, 0x2, 0x2, 0x28, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x172, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x18d, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x199, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1e1, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1ea, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x202, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x205, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x209, 0x3, 0x2, 0x2, 0x2, 0x42, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x46, 0x229, 0x3, 0x2, 0x2, 0x2, 0x48, 0x237, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x245, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x259, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x286, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x288, 0x3, 0x2, 0x2, 0x2, 0x54, 0x29e, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x58, 0x2cd, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x305, 0x3, 0x2, 0x2, 0x2, 0x60, 0x307, 0x3, 0x2, 0x2, 0x2, 0x62, 0x314, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x316, 0x3, 0x2, 0x2, 0x2, 0x66, 0x318, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x31c, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x320, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x322, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x324, 0x3, 0x2, 0x2, 0x2, 0x72, 0x335, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x337, 0x3, 0x2, 0x2, 0x2, 0x76, 0x339, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x33b, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x367, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x380, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 0x7, 
    0x3e, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x5, 0x4, 0x3, 
    0x2, 0x84, 0x85, 0x7, 0x2, 0x2, 0x3, 0x85, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x87, 0x5, 0x6, 0x4, 0x2, 0x87, 0x5, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x89, 0x5, 0x8, 0x5, 0x2, 0x89, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8c, 
    0x5, 0xa, 0x6, 0x2, 0x8b, 0x8d, 0x7, 0x3e, 0x2, 0x2, 0x8c, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x93, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x93, 
    0xae, 0x5, 0x18, 0xd, 0x2, 0x94, 0x96, 0x5, 0xa, 0x6, 0x2, 0x95, 0x97, 
    0x7, 0x3e, 0x2, 0x2, 0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x99, 0x3, 0x2, 0x2, 0x2, 0x98, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa4, 0x5, 0xe, 0x8, 0x2, 0x9e, 
    0xa0, 0x7, 0x3e, 0x2, 0x2, 0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x5, 
    0xe, 0x8, 0x2, 0xa2, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0xa9, 0x7, 0x3e, 0x2, 0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xac, 
    0x5, 0x18, 0xd, 0x2, 0xab, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xae, 0x3, 0x2, 0x2, 0x2, 0xad, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xae, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb0, 0x5, 0xc, 0x7, 0x2, 0xb0, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb3, 0x7, 0x4, 0x2, 0x2, 0xb2, 0xb4, 0x7, 0x3e, 0x2, 0x2, 0xb3, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0xba, 0x5, 0x2a, 0x16, 0x2, 0xb6, 0xb8, 0x7, 
    0x3e, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbb, 0x5, 0x20, 0x11, 
    0x2, 0xba, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xd, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xc0, 0x5, 0x10, 0x9, 0x2, 0xbd, 
    0xc0, 0x5, 0x12, 0xa, 0x2, 0xbe, 0xc0, 0x5, 0x14, 0xb, 0x2, 0xbf, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x7, 0x5, 
    0x2, 0x2, 0xc2, 0xc4, 0x7, 0x3e, 0x2, 0x2, 0xc3, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xc6, 0x5, 0x2a, 0x16, 0x2, 0xc6, 0x11, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc9, 0x7, 0x1b, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x7, 
    0x6, 0x2, 0x2, 0xcb, 0xcd, 0x7, 0x3e, 0x2, 0x2, 0xcc, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xd9, 0x5, 0x44, 0x23, 0x2, 0xcf, 0xd1, 0x7, 0x3e, 0x2, 0x2, 
    0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x7, 0x2b, 0x2, 0x2, 0xd3, 0xd5, 
    0x7, 0x3e, 0x2, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd8, 0x5, 0x44, 
    0x23, 0x2, 0xd7, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0x13, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 
    0xde, 0x7, 0x7, 0x2, 0x2, 0xdd, 0xdf, 0x7, 0x3e, 0x2, 0x2, 0xde, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xeb, 0x5, 0x16, 0xc, 0x2, 0xe1, 0xe3, 0x7, 0x3e, 
    0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x7, 0x2b, 0x2, 0x2, 
    0xe5, 0xe7, 0x7, 0x3e, 0x2, 0x2, 0xe6, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe6, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 
    0x5, 0x16, 0xc, 0x2, 0xe9, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xea, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0x15, 0x3, 0x2, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xf0, 0x5, 0x60, 0x31, 0x2, 0xef, 0xf1, 0x7, 0x3e, 0x2, 0x2, 
    0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf4, 0x7, 0x1c, 0x2, 0x2, 0xf3, 0xf5, 
    0x7, 0x3e, 0x2, 0x2, 0xf4, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x44, 
    0x23, 0x2, 0xf7, 0x109, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfa, 0x5, 0x6a, 0x36, 
    0x2, 0xf9, 0xfb, 0x7, 0x3e, 0x2, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfe, 0x7, 0x1c, 0x2, 0x2, 0xfd, 0xff, 0x7, 0x3e, 0x2, 0x2, 0xfe, 0xfd, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x100, 0x101, 0x5, 0x44, 0x23, 0x2, 0x101, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x104, 0x5, 0x6a, 0x36, 0x2, 0x103, 0x105, 0x7, 
    0x3e, 0x2, 0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x5, 
    0x3e, 0x20, 0x2, 0x107, 0x109, 0x3, 0x2, 0x2, 0x2, 0x108, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x108, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x109, 0x17, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10f, 0x7, 0x8, 0x2, 
    0x2, 0x10b, 0x10d, 0x7, 0x3e, 0x2, 0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 
    0x2, 0x10e, 0x110, 0x7, 0xe, 0x2, 0x2, 0x10f, 0x10c, 0x3, 0x2, 0x2, 
    0x2, 0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x111, 0x112, 0x7, 0x3e, 0x2, 0x2, 0x112, 0x113, 0x5, 0x1a, 0xe, 
    0x2, 0x113, 0x19, 0x3, 0x2, 0x2, 0x2, 0x114, 0x119, 0x5, 0x1c, 0xf, 
    0x2, 0x115, 0x117, 0x7, 0x3e, 0x2, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x118, 0x11a, 0x5, 0x22, 0x12, 0x2, 0x119, 0x116, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11d, 0x7, 0x3e, 0x2, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x120, 0x5, 0x26, 0x14, 0x2, 0x11f, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x123, 0x7, 0x3e, 0x2, 0x2, 0x122, 0x121, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x124, 0x126, 0x5, 0x28, 0x15, 0x2, 0x125, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x127, 0x137, 0x7, 0x3, 0x2, 0x2, 0x128, 0x133, 0x5, 0x1e, 0x10, 0x2, 
    0x129, 0x12b, 0x7, 0x3e, 0x2, 0x2, 0x12a, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x12e, 0x7, 0x2b, 0x2, 0x2, 0x12d, 0x12f, 0x7, 0x3e, 0x2, 0x2, 
    0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x132, 0x5, 0x1e, 0x10, 0x2, 
    0x131, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x132, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x3, 0x2, 0x2, 0x2, 
    0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x136, 0x127, 0x3, 0x2, 0x2, 0x2, 0x136, 0x128, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x138, 0x141, 0x5, 0x44, 0x23, 0x2, 
    0x139, 0x13b, 0x7, 0x3e, 0x2, 0x2, 0x13a, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13e, 0x7, 0x1a, 0x2, 0x2, 0x13d, 0x13f, 0x7, 0x3e, 0x2, 0x2, 
    0x13e, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x142, 0x5, 0x6a, 0x36, 0x2, 
    0x141, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x143, 0x145, 0x7, 0x9, 0x2, 0x2, 0x144, 
    0x146, 0x7, 0x3e, 0x2, 0x2, 0x145, 0x144, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 0x2, 0x2, 0x147, 
    0x148, 0x5, 0x44, 0x23, 0x2, 0x148, 0x21, 0x3, 0x2, 0x2, 0x2, 0x149, 
    0x14a, 0x7, 0x11, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x3e, 0x2, 0x2, 0x14b, 
    0x14c, 0x7, 0x12, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x3e, 0x2, 0x2, 0x14d, 
    0x158, 0x5, 0x24, 0x13, 0x2, 0x14e, 0x150, 0x7, 0x3e, 0x2, 0x2, 0x14f, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 
    0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x153, 0x7, 0x2b, 0x2, 0x2, 0x152, 
    0x154, 0x7, 0x3e, 0x2, 0x2, 0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 0x153, 
    0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 
    0x157, 0x5, 0x24, 0x13, 0x2, 0x156, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x157, 
    0x15a, 0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x23, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 
    0x3, 0x2, 0x2, 0x2, 0x15b, 0x164, 0x5, 0x44, 0x23, 0x2, 0x15c, 0x15e, 
    0x7, 0x3e, 0x2, 0x2, 0x15d, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x165, 
    0x7, 0x13, 0x2, 0x2, 0x160, 0x162, 0x7, 0x3e, 0x2, 0x2, 0x161, 0x160, 
    0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 
    0x3, 0x2, 0x2, 0x2, 0x163, 0x165, 0x7, 0x14, 0x2, 0x2, 0x164, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x164, 0x161, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x25, 0x3, 0x2, 0x2, 0x2, 0x166, 0x168, 0x7, 
    0x10, 0x2, 0x2, 0x167, 0x169, 0x7, 0x3e, 0x2, 0x2, 0x168, 0x167, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x16a, 0x16b, 0x5, 0x44, 0x23, 0x2, 0x16b, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x16c, 0x16e, 0x7, 0xf, 0x2, 0x2, 0x16d, 0x16f, 0x7, 
    0x3e, 0x2, 0x2, 0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 
    0x2, 0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x5, 
    0x44, 0x23, 0x2, 0x171, 0x29, 0x3, 0x2, 0x2, 0x2, 0x172, 0x17d, 0x5, 
    0x2c, 0x17, 0x2, 0x173, 0x175, 0x7, 0x3e, 0x2, 0x2, 0x174, 0x173, 0x3, 
    0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 
    0x2, 0x2, 0x2, 0x176, 0x178, 0x7, 0x2b, 0x2, 0x2, 0x177, 0x179, 0x7, 
    0x3e, 0x2, 0x2, 0x178, 0x177, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 
    0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17c, 0x5, 
    0x2c, 0x17, 0x2, 0x17b, 0x174, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17f, 0x3, 
    0x2, 0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 
    0x2, 0x2, 0x2, 0x17e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x180, 0x182, 0x5, 0x6a, 0x36, 0x2, 0x181, 0x183, 0x7, 0x3e, 
    0x2, 0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 0x2, 0x2, 0x184, 0x186, 0x7, 0x1c, 
    0x2, 0x2, 0x185, 0x187, 0x7, 0x3e, 0x2, 0x2, 0x186, 0x185, 0x3, 0x2, 
    0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x188, 0x189, 0x5, 0x2e, 0x18, 0x2, 0x189, 0x18c, 0x3, 0x2, 
    0x2, 0x2, 0x18a, 0x18c, 0x5, 0x2e, 0x18, 0x2, 0x18b, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x18e, 0x5, 0x30, 0x19, 0x2, 0x18e, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x18f, 0x196, 0x5, 0x34, 0x1b, 0x2, 0x190, 0x192, 0x7, 0x3e, 0x2, 
    0x2, 0x191, 0x190, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x3, 0x2, 0x2, 
    0x2, 0x192, 0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x195, 0x5, 0x32, 0x1a, 
    0x2, 0x194, 0x191, 0x3, 0x2, 0x2, 0x2, 0x195, 0x198, 0x3, 0x2, 0x2, 
    0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x31, 0x3, 0x2, 0x2, 0x2, 0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 
    0x199, 0x19b, 0x5, 0x36, 0x1c, 0x2, 0x19a, 0x19c, 0x7, 0x3e, 0x2, 0x2, 
    0x19b, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x19c, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x5, 0x34, 0x1b, 0x2, 
    0x19e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a1, 0x7, 0x33, 0x2, 0x2, 
    0x1a0, 0x1a2, 0x7, 0x3e, 0x2, 0x2, 0x1a1, 0x1a0, 0x3, 0x2, 0x2, 0x2, 
    0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a4, 0x3, 0x2, 0x2, 0x2, 
    0x1a3, 0x1a5, 0x5, 0x6a, 0x36, 0x2, 0x1a4, 0x1a3, 0x3, 0x2, 0x2, 0x2, 
    0x1a4, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a7, 0x3, 0x2, 0x2, 0x2, 
    0x1a6, 0x1a8, 0x7, 0x3e, 0x2, 0x2, 0x1a7, 0x1a6, 0x3, 0x2, 0x2, 0x2, 
    0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x1a9, 0x1ab, 0x5, 0x3e, 0x20, 0x2, 0x1aa, 0x1a9, 0x3, 0x2, 0x2, 0x2, 
    0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ad, 0x3, 0x2, 0x2, 0x2, 
    0x1ac, 0x1ae, 0x7, 0x3e, 0x2, 0x2, 0x1ad, 0x1ac, 0x3, 0x2, 0x2, 0x2, 
    0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 0x3, 0x2, 0x2, 0x2, 
    0x1af, 0x1b1, 0x5, 0x3c, 0x1f, 0x2, 0x1b0, 0x1af, 0x3, 0x2, 0x2, 0x2, 
    0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b3, 0x3, 0x2, 0x2, 0x2, 
    0x1b2, 0x1b4, 0x7, 0x3e, 0x2, 0x2, 0x1b3, 0x1b2, 0x3, 0x2, 0x2, 0x2, 
    0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 
    0x1b5, 0x1b6, 0x7, 0x34, 0x2, 0x2, 0x1b6, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x1b7, 0x1b9, 0x7, 0x2a, 0x2, 0x2, 0x1b8, 0x1ba, 0x7, 0x3e, 0x2, 0x2, 
    0x1b9, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bd, 0x5, 0x3a, 0x1e, 0x2, 
    0x1bc, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x1bd, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c0, 0x7, 0x3e, 0x2, 0x2, 
    0x1bf, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x3, 0x2, 0x2, 0x2, 
    0x1c0, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c3, 0x7, 0x2a, 0x2, 0x2, 
    0x1c2, 0x1c4, 0x7, 0x3e, 0x2, 0x2, 0x1c3, 0x1c2, 0x3, 0x2, 0x2, 0x2, 
    0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 
    0x1c5, 0x1e2, 0x5, 0x38, 0x1d, 0x2, 0x1c6, 0x1c8, 0x5, 0x38, 0x1d, 0x2, 
    0x1c7, 0x1c9, 0x7, 0x3e, 0x2, 0x2, 0x1c8, 0x1c7, 0x3, 0x2, 0x2, 0x2, 
    0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 0x2, 0x2, 
    0x1ca, 0x1cc, 0x7, 0x2a, 0x2, 0x2, 0x1cb, 0x1cd, 0x7, 0x3e, 0x2, 0x2, 
    0x1cc, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 
    0x1cd, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1d0, 0x5, 0x3a, 0x1e, 0x2, 
    0x1cf, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x3, 0x2, 0x2, 0x2, 
    0x1d0, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d3, 0x7, 0x3e, 0x2, 0x2, 
    0x1d2, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x7, 0x2a, 0x2, 0x2, 
    0x1d5, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d8, 0x7, 0x2a, 0x2, 0x2, 
    0x1d7, 0x1d9, 0x7, 0x3e, 0x2, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 
    0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1db, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x1dc, 0x5, 0x3a, 0x1e, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1db, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1de, 0x3, 0x2, 0x2, 0x2, 
    0x1dd, 0x1df, 0x7, 0x3e, 0x2, 0x2, 0x1de, 0x1dd, 0x3, 0x2, 0x2, 0x2, 
    0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 
    0x1e0, 0x1e2, 0x7, 0x2a, 0x2, 0x2, 0x1e1, 0x1b7, 0x3, 0x2, 0x2, 0x2, 
    0x1e1, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1d6, 0x3, 0x2, 0x2, 0x2, 
    0x1e2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x1e, 0x2, 0x2, 
    0x1e4, 0x1e5, 0x7, 0x23, 0x2, 0x2, 0x1e5, 0x1e9, 0x7, 0x1f, 0x2, 0x2, 
    0x1e6, 0x1e7, 0x7, 0x23, 0x2, 0x2, 0x1e7, 0x1e9, 0x7, 0x1f, 0x2, 0x2, 
    0x1e8, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 
    0x1e9, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ec, 0x7, 0x37, 0x2, 0x2, 
    0x1eb, 0x1ed, 0x7, 0x3e, 0x2, 0x2, 0x1ec, 0x1eb, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ef, 0x3, 0x2, 0x2, 0x2, 
    0x1ee, 0x1f0, 0x5, 0x6a, 0x36, 0x2, 0x1ef, 0x1ee, 0x3, 0x2, 0x2, 0x2, 
    0x1ef, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f2, 0x3, 0x2, 0x2, 0x2, 
    0x1f1, 0x1f3, 0x7, 0x3e, 0x2, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x3, 0x2, 0x2, 0x2, 
    0x1f4, 0x1f6, 0x5, 0x42, 0x22, 0x2, 0x1f5, 0x1f4, 0x3, 0x2, 0x2, 0x2, 
    0x1f5, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f8, 0x3, 0x2, 0x2, 0x2, 
    0x1f7, 0x1f9, 0x7, 0x3e, 0x2, 0x2, 0x1f8, 0x1f7, 0x3, 0x2, 0x2, 0x2, 
    0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fa, 0x1fc, 0x5, 0x3c, 0x1f, 0x2, 0x1fb, 0x1fa, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fe, 0x3, 0x2, 0x2, 0x2, 
    0x1fd, 0x1ff, 0x7, 0x3e, 0x2, 0x2, 0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 
    0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x3, 0x2, 0x2, 0x2, 
    0x200, 0x201, 0x7, 0x38, 0x2, 0x2, 0x201, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x202, 0x203, 0x5, 0x7a, 0x3e, 0x2, 0x203, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x204, 0x206, 0x5, 0x40, 0x21, 0x2, 0x205, 0x204, 0x3, 0x2, 0x2, 0x2, 
    0x206, 0x207, 0x3, 0x2, 0x2, 0x2, 0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 
    0x207, 0x208, 0x3, 0x2, 0x2, 0x2, 0x208, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x209, 
    0x20b, 0x7, 0x2c, 0x2, 0x2, 0x20a, 0x20c, 0x7, 0x3e, 0x2, 0x2, 0x20b, 
    0x20a, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20c, 
    0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x5, 0x64, 0x33, 0x2, 0x20e, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x211, 0x7, 0x2c, 0x2, 0x2, 0x210, 
    0x212, 0x7, 0x3e, 0x2, 0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 0x211, 
    0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 
    0x224, 0x5, 0x66, 0x34, 0x2, 0x214, 0x216, 0x7, 0x3e, 0x2, 0x2, 0x215, 
    0x214, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x3, 0x2, 0x2, 0x2, 0x216, 
    0x217, 0x3, 0x2, 0x2, 0x2, 0x217, 0x219, 0x7, 0x27, 0x2, 0x2, 0x218, 
    0x21a, 0x7, 0x3e, 0x2, 0x2, 0x219, 0x218, 0x3, 0x2, 0x2, 0x2, 0x219, 
    0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21b, 
    0x21d, 0x7, 0x2c, 0x2, 0x2, 0x21c, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21c, 
    0x21d, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x21e, 
    0x220, 0x7, 0x3e, 0x2, 0x2, 0x21f, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x21f, 
    0x220, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 0x2, 0x2, 0x2, 0x221, 
    0x223, 0x5, 0x66, 0x34, 0x2, 0x222, 0x215, 0x3, 0x2, 0x2, 0x2, 0x223, 
    0x226, 0x3, 0x2, 0x2, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 
    0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 0x43, 0x3, 0x2, 0x2, 0x2, 0x226, 0x224, 
    0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x5, 0x46, 0x24, 0x2, 0x228, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x229, 0x234, 0x5, 0x48, 0x25, 0x2, 0x22a, 0x22c, 
    0x7, 0x3e, 0x2, 0x2, 0x22b, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 
    0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22f, 
    0x7, 0xb, 0x2, 0x2, 0x22e, 0x230, 0x7, 0x3e, 0x2, 0x2, 0x22f, 0x22e, 
    0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 
    0x3, 0x2, 0x2, 0x2, 0x231, 0x233, 0x5, 0x48, 0x25, 0x2, 0x232, 0x22b, 
    0x3, 0x2, 0x2, 0x2, 0x233, 0x236, 0x3, 0x2, 0x2, 0x2, 0x234, 0x232, 
    0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 0x2, 0x2, 0x235, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x236, 0x234, 0x3, 0x2, 0x2, 0x2, 0x237, 0x242, 0x5, 
    0x4a, 0x26, 0x2, 0x238, 0x23a, 0x7, 0x3e, 0x2, 0x2, 0x239, 0x238, 0x3, 
    0x2, 0x2, 0x2, 0x239, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x3, 
    0x2, 0x2, 0x2, 0x23b, 0x23d, 0x7, 0xc, 0x2, 0x2, 0x23c, 0x23e, 0x7, 
    0x3e, 0x2, 0x2, 0x23d, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x3, 
    0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x241, 0x5, 
    0x4a, 0x26, 0x2, 0x240, 0x239, 0x3, 0x2, 0x2, 0x2, 0x241, 0x244, 0x3, 
    0x2, 0x2, 0x2, 0x242, 0x240, 0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 
    0x2, 0x2, 0x2, 0x243, 0x49, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 
    0x2, 0x2, 0x245, 0x250, 0x5, 0x4c, 0x27, 0x2, 0x246, 0x248, 0x7, 0x3e, 
    0x2, 0x2, 0x247, 0x246, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x3, 0x2, 
    0x2, 0x2, 0x248, 0x249, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24b, 0x7, 0xa, 
    0x2, 0x2, 0x24a, 0x24c, 0x7, 0x3e, 0x2, 0x2, 0x24b, 0x24a, 0x3, 0x2, 
    0x2, 0x2, 0x24b, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 
    0x2, 0x2, 0x24d, 0x24f, 0x5, 0x4c, 0x27, 0x2, 0x24e, 0x247, 0x3, 0x2, 
    0x2, 0x2, 0x24f, 0x252, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 0x2, 
    0x2, 0x2, 0x250, 0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x250, 0x3, 0x2, 0x2, 0x2, 0x253, 0x255, 0x7, 0xd, 0x2, 
    0x2, 0x254, 0x256, 0x7, 0x3e, 0x2, 0x2, 0x255, 0x254, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x258, 0x3, 0x2, 0x2, 
    0x2, 0x257, 0x253, 0x3, 0x2, 0x2, 0x2, 0x258, 0x25b, 0x3, 0x2, 0x2, 
    0x2, 0x259, 0x257, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x3, 0x2, 0x2, 
    0x2, 0x25a, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x259, 0x3, 0x2, 0x2, 
    0x2, 0x25c, 0x25d, 0x5, 0x4e, 0x28, 0x2, 0x25d, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x25e, 0x265, 0x5, 0x52, 0x2a, 0x2, 0x25f, 0x261, 0x7, 0x3e, 0x2, 
    0x2, 0x260, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0x3, 0x2, 0x2, 
    0x2, 0x261, 0x262, 0x3, 0x2, 0x2, 0x2, 0x262, 0x264, 0x5, 0x50, 0x29, 
    0x2, 0x263, 0x260, 0x3, 0x2, 0x2, 0x2, 0x264, 0x267, 0x3, 0x2, 0x2, 
    0x2, 0x265, 0x263, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x3, 0x2, 0x2, 
    0x2, 0x266, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x267, 0x265, 0x3, 0x2, 0x2, 0x2, 
    0x268, 0x26a, 0x7, 0x1c, 0x2, 0x2, 0x269, 0x26b, 0x7, 0x3e, 0x2, 0x2, 
    0x26a, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x287, 0x5, 0x52, 0x2a, 0x2, 
    0x26d, 0x26f, 0x7, 0x1d, 0x2, 0x2, 0x26e, 0x270, 0x7, 0x3e, 0x2, 0x2, 
    0x26f, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 
    0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 0x271, 0x287, 0x5, 0x52, 0x2a, 0x2, 
    0x272, 0x274, 0x7, 0x1e, 0x2, 0x2, 0x273, 0x275, 0x7, 0x3e, 0x2, 0x2, 
    0x274, 0x273, 0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x275, 0x276, 0x3, 0x2, 0x2, 0x2, 0x276, 0x287, 0x5, 0x52, 0x2a, 0x2, 
    0x277, 0x279, 0x7, 0x1f, 0x2, 0x2, 0x278, 0x27a, 0x7, 0x3e, 0x2, 0x2, 
    0x279, 0x278, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x3, 0x2, 0x2, 0x2, 
    0x27a, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x287, 0x5, 0x52, 0x2a, 0x2, 
    0x27c, 0x27e, 0x7, 0x20, 0x2, 0x2, 0x27d, 0x27f, 0x7, 0x3e, 0x2, 0x2, 
    0x27e, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x3, 0x2, 0x2, 0x2, 
    0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 0x280, 0x287, 0x5, 0x52, 0x2a, 0x2, 
    0x281, 0x283, 0x7, 0x21, 0x2, 0x2, 0x282, 0x284, 0x7, 0x3e, 0x2, 0x2, 
    0x283, 0x282, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x3, 0x2, 0x2, 0x2, 
    0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 0x287, 0x5, 0x52, 0x2a, 0x2, 
    0x286, 0x268, 0x3, 0x2, 0x2, 0x2, 0x286, 0x26d, 0x3, 0x2, 0x2, 0x2, 
    0x286, 0x272, 0x3, 0x2, 0x2, 0x2, 0x286, 0x277, 0x3, 0x2, 0x2, 0x2, 
    0x286, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x286, 0x281, 0x3, 0x2, 0x2, 0x2, 
    0x287, 0x51, 0x3, 0x2, 0x2, 0x2, 0x288, 0x29b, 0x5, 0x54, 0x2b, 0x2, 
    0x289, 0x28b, 0x7, 0x3e, 0x2, 0x2, 0x28a, 0x289, 0x3, 0x2, 0x2, 0x2, 
    0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x3, 0x2, 0x2, 0x2, 
    0x28c, 0x28e, 0x7, 0x22, 0x2, 0x2, 0x28d, 0x28f, 0x7, 0x3e, 0x2, 0x2, 
    0x28e, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x3, 0x2, 0x2, 0x2, 
    0x28f, 0x290, 0x3, 0x2, 0x2, 0x2, 0x290, 0x29a, 0x5, 0x54, 0x2b, 0x2, 
    0x291, 0x293, 0x7, 0x3e, 0x2, 0x2, 0x292, 0x291, 0x3, 0x2, 0x2, 0x2, 
    0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 0x2, 0x2, 
    0x294, 0x296, 0x7, 0x23, 0x2, 0x2, 0x295, 0x297, 0x7, 0x3e, 0x2, 0x2, 
    0x296, 0x295, 0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x3, 0x2, 0x2, 0x2, 
    0x297, 0x298, 0x3, 0x2, 0x2, 0x2, 0x298, 0x29a, 0x5, 0x54, 0x2b, 0x2, 
    0x299, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x299, 0x292, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x299, 0x3, 0x2, 0x2, 0x2, 
    0x29b, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x53, 0x3, 0x2, 0x2, 0x2, 0x29d, 
    0x29b, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x2b9, 0x5, 0x56, 0x2c, 0x2, 0x29f, 
    0x2a1, 0x7, 0x3e, 0x2, 0x2, 0x2a0, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
    0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a2, 
    0x2a4, 0x7, 0x41, 0x2, 0x2, 0x2a3, 0x2a5, 0x7, 0x3e, 0x2, 0x2, 0x2a4, 
    0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a5, 
    0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2b8, 0x5, 0x56, 0x2c, 0x2, 0x2a7, 
    0x2a9, 0x7, 0x3e, 0x2, 0x2, 0x2a8, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a8, 
    0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x2ac, 0x7, 0x24, 0x2, 0x2, 0x2ab, 0x2ad, 0x7, 0x3e, 0x2, 0x2, 0x2ac, 
    0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b8, 0x5, 0x56, 0x2c, 0x2, 0x2af, 
    0x2b1, 0x7, 0x3e, 0x2, 0x2, 0x2b0, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
    0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b2, 
    0x2b4, 0x7, 0x25, 0x2, 0x2, 0x2b3, 0x2b5, 0x7, 0x3e, 0x2, 0x2, 0x2b4, 
    0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b5, 
    0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b8, 0x5, 0x56, 0x2c, 0x2, 0x2b7, 
    0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2b7, 
    0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2b9, 
    0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2c7, 
    0x5, 0x58, 0x2d, 0x2, 0x2bd, 0x2bf, 0x7, 0x3e, 0x2, 0x2, 0x2be, 0x2bd, 
    0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c0, 
    0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c2, 0x7, 0x26, 0x2, 0x2, 0x2c1, 0x2c3, 
    0x7, 0x3e, 0x2, 0x2, 0x2c2, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 
    0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c6, 
    0x5, 0x58, 0x2d, 0x2, 0x2c5, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c9, 
    0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c8, 
    0x3, 0x2, 0x2, 0x2, 0x2c8, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2c7, 0x3, 
    0x2, 0x2, 0x2, 0x2ca, 0x2cc, 0x9, 0x2, 0x2, 0x2, 0x2cb, 0x2ca, 0x3, 
    0x2, 0x2, 0x2, 0x2cc, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2cb, 0x3, 
    0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2d0, 0x3, 
    0x2, 0x2, 0x2, 0x2cf, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x5, 
    0x5a, 0x2e, 0x2, 0x2d1, 0x59, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2e1, 0x5, 
    0x72, 0x3a, 0x2, 0x2d3, 0x2e1, 0x5, 0x7e, 0x40, 0x2, 0x2d4, 0x2e1, 0x5, 
    0x5c, 0x2f, 0x2, 0x2d5, 0x2e1, 0x5, 0x6a, 0x36, 0x2, 0x2d6, 0x2d8, 0x7, 
    0x33, 0x2, 0x2, 0x2d7, 0x2d9, 0x7, 0x3e, 0x2, 0x2, 0x2d8, 0x2d7, 0x3, 
    0x2, 0x2, 0x2, 0x2d8, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x3, 
    0x2, 0x2, 0x2, 0x2da, 0x2dc, 0x5, 0x44, 0x23, 0x2, 0x2db, 0x2dd, 0x7, 
    0x3e, 0x2, 0x2, 0x2dc, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0x3, 
    0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x7, 
    0x34, 0x2, 0x2, 0x2df, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2d2, 0x3, 
    0x2, 0x2, 0x2, 0x2e0, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2d4, 0x3, 
    0x2, 0x2, 0x2, 0x2e0, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2d6, 0x3, 
    0x2, 0x2, 0x2, 0x2e1, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e4, 0x5, 0x5e, 
    0x30, 0x2, 0x2e3, 0x2e5, 0x7, 0x3e, 0x2, 0x2, 0x2e4, 0x2e3, 0x3, 0x2, 
    0x2, 0x2, 0x2e4, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x3, 0x2, 
    0x2, 0x2, 0x2e6, 0x2e8, 0x7, 0x33, 0x2, 0x2, 0x2e7, 0x2e9, 0x7, 0x3e, 
    0x2, 0x2, 0x2e8, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 0x3, 0x2, 
    0x2, 0x2, 0x2e9, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2ec, 0x7, 0xe, 
    0x2, 0x2, 0x2eb, 0x2ed, 0x7, 0x3e, 0x2, 0x2, 0x2ec, 0x2eb, 0x3, 0x2, 
    0x2, 0x2, 0x2ec, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ef, 0x3, 0x2, 
    0x2, 0x2, 0x2ee, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x3, 0x2, 
    0x2, 0x2, 0x2ef, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2fb, 0x5, 0x44, 
    0x23, 0x2, 0x2f1, 0x2f3, 0x7, 0x3e, 0x2, 0x2, 0x2f2, 0x2f1, 0x3, 0x2, 
    0x2, 0x2, 0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x3, 0x2, 
    0x2, 0x2, 0x2f4, 0x2f6, 0x7, 0x2b, 0x2, 0x2, 0x2f5, 0x2f7, 0x7, 0x3e, 
    0x2, 0x2, 0x2f6, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x3, 0x2, 
    0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2fa, 0x5, 0x44, 
    0x23, 0x2, 0x2f9, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fd, 0x3, 0x2, 
    0x2, 0x2, 0x2fb, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 0x3, 0x2, 
    0x2, 0x2, 0x2fc, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fb, 0x3, 0x2, 
    0x2, 0x2, 0x2fe, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2ff, 0x3, 0x2, 
    0x2, 0x2, 0x2ff, 0x301, 0x3, 0x2, 0x2, 0x2, 0x300, 0x302, 0x7, 0x3e, 
    0x2, 0x2, 0x301, 0x300, 0x3, 0x2, 0x2, 0x2, 0x301, 0x302, 0x3, 0x2, 
    0x2, 0x2, 0x302, 0x303, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 0x7, 0x34, 
    0x2, 0x2, 0x304, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0x5, 0x6c, 
    0x37, 0x2, 0x306, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x307, 0x310, 0x5, 0x5a, 
    0x2e, 0x2, 0x308, 0x30a, 0x7, 0x3e, 0x2, 0x2, 0x309, 0x308, 0x3, 0x2, 
    0x2, 0x2, 0x309, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x30b, 0x3, 0x2, 
    0x2, 0x2, 0x30b, 0x30d, 0x7, 0x29, 0x2, 0x2, 0x30c, 0x30e, 0x7, 0x3e, 
    0x2, 0x2, 0x30d, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30e, 0x3, 0x2, 
    0x2, 0x2, 0x30e, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x311, 0x5, 0x62, 
    0x32, 0x2, 0x310, 0x309, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0x3, 0x2, 
    0x2, 0x2, 0x312, 0x310, 0x3, 0x2, 0x2, 0x2, 0x312, 0x313, 0x3, 0x2, 
    0x2, 0x2, 0x313, 0x61, 0x3, 0x2, 0x2, 0x2, 0x314, 0x315, 0x5, 0x68, 
    0x35, 0x2, 0x315, 0x63, 0x3, 0x2, 0x2, 0x2, 0x316, 0x317, 0x5, 0x68, 
    0x35, 0x2, 0x317, 0x65, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 0x5, 0x68, 
    0x35, 0x2, 0x319, 0x67, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31b, 0x5, 0x6c, 
    0x37, 0x2, 0x31b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 0x5, 0x6c, 
    0x37, 0x2, 0x31d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x321, 0x5, 0x6e, 
    0x38, 0x2, 0x31f, 0x321, 0x5, 0x70, 0x39, 0x2, 0x320, 0x31e, 0x3, 0x2, 
    0x2, 0x2, 0x320, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x322, 0x323, 0x7, 0x3d, 0x2, 0x2, 0x323, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x324, 0x32a, 0x7, 0x39, 0x2, 0x2, 0x325, 0x329, 0xa, 0x3, 0x2, 
    0x2, 0x326, 0x327, 0x7, 0x39, 0x2, 0x2, 0x327, 0x329, 0x7, 0x39, 0x2, 
    0x2, 0x328, 0x325, 0x3, 0x2, 0x2, 0x2, 0x328, 0x326, 0x3, 0x2, 0x2, 
    0x2, 0x329, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x328, 0x3, 0x2, 0x2, 
    0x2, 0x32a, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32d, 0x3, 0x2, 0x2, 
    0x2, 0x32c, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x32e, 0x7, 0x39, 0x2, 
    0x2, 0x32e, 0x71, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x336, 0x5, 0x74, 0x3b, 
    0x2, 0x330, 0x336, 0x5, 0x76, 0x3c, 0x2, 0x331, 0x336, 0x5, 0x78, 0x3d, 
    0x2, 0x332, 0x336, 0x7, 0x15, 0x2, 0x2, 0x333, 0x336, 0x5, 0x7a, 0x3e, 
    0x2, 0x334, 0x336, 0x5, 0x7c, 0x3f, 0x2, 0x335, 0x32f, 0x3, 0x2, 0x2, 
    0x2, 0x335, 0x330, 0x3, 0x2, 0x2, 0x2, 0x335, 0x331, 0x3, 0x2, 0x2, 
    0x2, 0x335, 0x332, 0x3, 0x2, 0x2, 0x2, 0x335, 0x333, 0x3, 0x2, 0x2, 
    0x2, 0x335, 0x334, 0x3, 0x2, 0x2, 0x2, 0x336, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x337, 0x338, 0x9, 0x4, 0x2, 0x2, 0x338, 0x75, 0x3, 0x2, 0x2, 0x2, 0x339, 
    0x33a, 0x7, 0x3a, 0x2, 0x2, 0x33a, 0x77, 0x3, 0x2, 0x2, 0x2, 0x33b, 
    0x33c, 0x9, 0x5, 0x2, 0x2, 0x33c, 0x79, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33f, 
    0x7, 0x35, 0x2, 0x2, 0x33e, 0x340, 0x7, 0x3e, 0x2, 0x2, 0x33f, 0x33e, 
    0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 0x360, 
    0x3, 0x2, 0x2, 0x2, 0x341, 0x343, 0x5, 0x62, 0x32, 0x2, 0x342, 0x344, 
    0x7, 0x3e, 0x2, 0x2, 0x343, 0x342, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 
    0x3, 0x2, 0x2, 0x2, 0x344, 0x345, 0x3, 0x2, 0x2, 0x2, 0x345, 0x347, 
    0x7, 0x2c, 0x2, 0x2, 0x346, 0x348, 0x7, 0x3e, 0x2, 0x2, 0x347, 0x346, 
    0x3, 0x2, 0x2, 0x2, 0x347, 0x348, 0x3, 0x2, 0x2, 0x2, 0x348, 0x349, 
    0x3, 0x2, 0x2, 0x2, 0x349, 0x35d, 0x5, 0x44, 0x23, 0x2, 0x34a, 0x34c, 
    0x7, 0x3e, 0x2, 0x2, 0x34b, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34c, 
    0x3, 0x2, 0x2, 0x2, 0x34c, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34f, 
    0x7, 0x2b, 0x2, 0x2, 0x34e, 0x350, 0x7, 0x3e, 0x2, 0x2, 0x34f, 0x34e, 
    0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x3, 0x2, 0x2, 0x2, 0x350, 0x351, 
    0x3, 0x2, 0x2, 0x2, 0x351, 0x353, 0x5, 0x62, 0x32, 0x2, 0x352, 0x354, 
    0x7, 0x3e, 0x2, 0x2, 0x353, 0x352, 0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 
    0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 0x3, 0x2, 0x2, 0x2, 0x355, 0x357, 
    0x7, 0x2c, 0x2, 0x2, 0x356, 0x358, 0x7, 0x3e, 0x2, 0x2, 0x357, 0x356, 
    0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 0x3, 0x2, 0x2, 0x2, 0x358, 0x359, 
    0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 0x5, 0x44, 0x23, 0x2, 0x35a, 0x35c, 
    0x3, 0x2, 0x2, 0x2, 0x35b, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35f, 
    0x3, 0x2, 0x2, 0x2, 0x35d, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 
    0x3, 0x2, 0x2, 0x2, 0x35e, 0x361, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x35d, 
    0x3, 0x2, 0x2, 0x2, 0x360, 0x341, 0x3, 0x2, 0x2, 0x2, 0x360, 0x361, 
    0x3, 0x2, 0x2, 0x2, 0x361, 0x363, 0x3, 0x2, 0x2, 0x2, 0x362, 0x364, 
    0x7, 0x3e, 0x2, 0x2, 0x363, 0x362, 0x3, 0x2, 0x2, 0x2, 0x363, 0x364, 
    0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x3, 0x2, 0x2, 0x2, 0x365, 0x366, 
    0x7, 0x36, 0x2, 0x2, 0x366, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x367, 0x369, 
    0x7, 0x37, 0x2, 0x2, 0x368, 0x36a, 0x7, 0x3e, 0x2, 0x2, 0x369, 0x368, 
    0x3, 0x2, 0x2, 0x2, 0x369, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x379, 
    0x3, 0x2, 0x2, 0x2, 0x36b, 0x376, 0x5, 0x44, 0x23, 0x2, 0x36c, 0x36e, 
    0x7, 0x3e, 0x2, 0x2, 0x36d, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36e, 
    0x3, 0x2, 0x2, 0x2, 0x36e, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x371, 
    0x7, 0x2b, 0x2, 0x2, 0x370, 0x372, 0x7, 0x3e, 0x2, 0x2, 0x371, 0x370, 
    0x3, 0x2, 0x2, 0x2, 0x371, 0x372, 0x3, 0x2, 0x2, 0x2, 0x372, 0x373, 
    0x3, 0x2, 0x2, 0x2, 0x373, 0x375, 0x5, 0x44, 0x23, 0x2, 0x374, 0x36d, 
    0x3, 0x2, 0x2, 0x2, 0x375, 0x378, 0x3, 0x2, 0x2, 0x2, 0x376, 0x374, 
    0x3, 0x2, 0x2, 0x2, 0x376, 0x377, 0x3, 0x2, 0x2, 0x2, 0x377, 0x37a, 
    0x3, 0x2, 0x2, 0x2, 0x378, 0x376, 0x3, 0x2, 0x2, 0x2, 0x379, 0x36b, 
    0x3, 0x2, 0x2, 0x2, 0x379, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37c, 
    0x3, 0x2, 0x2, 0x2, 0x37b, 0x37d, 0x7, 0x3e, 0x2, 0x2, 0x37c, 0x37b, 
    0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 
    0x3, 0x2, 0x2, 0x2, 0x37e, 0x37f, 0x7, 0x38, 0x2, 0x2, 0x37f, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x380, 0x381, 0x7, 0x2e, 0x2, 0x2, 0x381, 0x382, 
    0x5, 0x6c, 0x37, 0x2, 0x382, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xad, 0x81, 0x8c, 
    0x90, 0x96, 0x9a, 0x9f, 0xa4, 0xa8, 0xab, 0xad, 0xb3, 0xb7, 0xba, 0xbf, 
    0xc3, 0xc8, 0xcc, 0xd0, 0xd4, 0xd9, 0xde, 0xe2, 0xe6, 0xeb, 0xf0, 0xf4, 
    0xfa, 0xfe, 0x104, 0x108, 0x10c, 0x10f, 0x116, 0x119, 0x11c, 0x11f, 
    0x122, 0x125, 0x12a, 0x12e, 0x133, 0x136, 0x13a, 0x13e, 0x141, 0x145, 
    0x14f, 0x153, 0x158, 0x15d, 0x161, 0x164, 0x168, 0x16e, 0x174, 0x178, 
    0x17d, 0x182, 0x186, 0x18b, 0x191, 0x196, 0x19b, 0x1a1, 0x1a4, 0x1a7, 
    0x1aa, 0x1ad, 0x1b0, 0x1b3, 0x1b9, 0x1bc, 0x1bf, 0x1c3, 0x1c8, 0x1cc, 
    0x1cf, 0x1d2, 0x1d8, 0x1db, 0x1de, 0x1e1, 0x1e8, 0x1ec, 0x1ef, 0x1f2, 
    0x1f5, 0x1f8, 0x1fb, 0x1fe, 0x207, 0x20b, 0x211, 0x215, 0x219, 0x21c, 
    0x21f, 0x224, 0x22b, 0x22f, 0x234, 0x239, 0x23d, 0x242, 0x247, 0x24b, 
    0x250, 0x255, 0x259, 0x260, 0x265, 0x26a, 0x26f, 0x274, 0x279, 0x27e, 
    0x283, 0x286, 0x28a, 0x28e, 0x292, 0x296, 0x299, 0x29b, 0x2a0, 0x2a4, 
    0x2a8, 0x2ac, 0x2b0, 0x2b4, 0x2b7, 0x2b9, 0x2be, 0x2c2, 0x2c7, 0x2cd, 
    0x2d8, 0x2dc, 0x2e0, 0x2e4, 0x2e8, 0x2ec, 0x2ee, 0x2f2, 0x2f6, 0x2fb, 
    0x2fe, 0x301, 0x309, 0x30d, 0x312, 0x320, 0x328, 0x32a, 0x335, 0x33f, 
    0x343, 0x347, 0x34b, 0x34f, 0x353, 0x357, 0x35d, 0x360, 0x363, 0x369, 
    0x36d, 0x371, 0x376, 0x379, 0x37c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CypherParser::Initializer CypherParser::_init;
