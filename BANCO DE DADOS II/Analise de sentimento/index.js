var Algorithmia = require("algorithmia");




var negative_sentiment = []

var input = {
  "query": "covid19"+"-filter:retweets",
  "numTweets": "10",
  "auth": {
      "app_key": 'ODBJeYCD9yMAfmOqIHM2iETMx',
      "app_secret": 'T132fpTrYEHds7yZ5SF0lsIjW0rFMDkSkRXOu2hPF9ZGmkzMae',
      "oauth_token":  '4035734715-26EXiWjeIEfgW1pz12zlWprx7pCDkx3PccFrWMV',
      "oauth_token_secret":  'EmZyPPxlkkDh1CzLUcJtIaFZtXsoLMaNJDpDApt2Fc0dg'
  }
};

Algorithmia.client("sim0xAq2VADAjqiDQ04fQTjMjtz1")
  .algo("nlp/AnalyzeTweets/0.1.13") // timeout is optional
  .pipe(input)
  .then(function(response) {
    console.log(response.get());
});
