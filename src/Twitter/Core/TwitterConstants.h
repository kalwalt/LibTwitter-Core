#ifndef H_TWITTERCONSTANTS_H
	#define H_TWITTERCONSTANTS_H

	#include <string>

	using namespace std;
	



const std::string DEFAULT_PROXY = "system_defined";

enum e_HTTP_request_type {
    INVALID = 0,
    GET,
    POST,
    DELETE
};


namespace e_HTTP_response_code {

	enum e_HTTP_response_code {
		UNDEFINED = 999,
		WAITING_RESPONSE = 1000,
		
		OK = 200,
		RATE_LIMIT = 88,
		NOT_FOUND = 404,
		NOT_ACCEPTABLE = 406,
		FLOOD = 429,

		NB_HTTP_CODES = 7
	};

};

/*
static const char* e_HTTP_response_code_Text[] {
	"No request !",
	"Waiting response ...",
	"OK",
	"Target not found",
	"Flood",
	"Not acceptable"
};
*/





namespace TwitterConsts {

	const string API_VERSION = "1.1";


	const string API_LINK = "http://api.twitter.com/"+API_VERSION+"/";
	const string STREAM_API_LINK = "http://stream.twitter.com/"+API_VERSION+"/";

	const string FORMAT = ".json";

	const string ACCOUNT = "account/";


/* BEGIN_PYGEN don't remove this comment (2012/9/26 22:31) */

	namespace STATUSES {

		const std::string STATUSES = "statuses/";

		const std::string MENTIONS_TIMELINE = API_LINK + STATUSES + "mentions_timeline" + FORMAT ;
		const std::string USER_TIMELINE = API_LINK + STATUSES + "user_timeline" + FORMAT ;
		const std::string HOME_TIMELINE = API_LINK + STATUSES + "home_timeline" + FORMAT ;
		const std::string RETWEETS = API_LINK + STATUSES + "retweets/:id" + FORMAT ;
		const std::string DESTROY = API_LINK + STATUSES + "destroy/:id" + FORMAT ;
		const std::string UPDATE = API_LINK + STATUSES + "update" + FORMAT ;
		const std::string RETWEET = API_LINK + STATUSES + "retweet/:id" + FORMAT ;
		const std::string OEMBED = API_LINK + STATUSES + "oembed" + FORMAT ;
	};

	namespace SEARCH {

		const std::string SEARCH = "search/";

		const std::string TWEETS = API_LINK + SEARCH + "tweets" + FORMAT ;
	};

	namespace DIRECT_MESSAGES {

		const std::string DIRECT_MESSAGES = "direct_messages/";

		const std::string SENT = API_LINK + DIRECT_MESSAGES + "sent" + FORMAT ;
		const std::string SHOW = API_LINK + DIRECT_MESSAGES + "show" + FORMAT ;
		const std::string DESTROY = API_LINK + DIRECT_MESSAGES + "destroy" + FORMAT ;
		const std::string NEW = API_LINK + DIRECT_MESSAGES + "new" + FORMAT ;
	};

	namespace FRIENDS {

		const std::string FRIENDS = "friends/";

		const std::string IDS = API_LINK + FRIENDS + "ids" + FORMAT ;
	};

	namespace FOLLOWERS {

		const std::string FOLLOWERS = "followers/";

		const std::string IDS = API_LINK + FOLLOWERS + "ids" + FORMAT ;
	};

	namespace FRIENDSHIPS {

		const std::string FRIENDSHIPS = "friendships/";

		const std::string LOOKUP = API_LINK + FRIENDSHIPS + "lookup" + FORMAT ;
		const std::string INCOMING = API_LINK + FRIENDSHIPS + "incoming" + FORMAT ;
		const std::string OUTGOING = API_LINK + FRIENDSHIPS + "outgoing" + FORMAT ;
		const std::string CREATE = API_LINK + FRIENDSHIPS + "create" + FORMAT ;
		const std::string DESTROY = API_LINK + FRIENDSHIPS + "destroy" + FORMAT ;
		const std::string UPDATE = API_LINK + FRIENDSHIPS + "update" + FORMAT ;
		const std::string SHOW = API_LINK + FRIENDSHIPS + "show" + FORMAT ;
	};

/* END_PYGEN don't remove this comment (2012/9/26 22:31) */

	namespace Streaming {

		const string STREAM_USER = "https://userstream.twitter.com/1.1/user.json";

	};


	namespace Tweets {

		const string UPDATE = API_LINK + "statuses/" + "update.json";

	};

	namespace Users {

		const string VERIFY_CREDENTIALS = API_LINK + ACCOUNT + "verify_credentials.json";

	};

	namespace Settings {

		const string GET_SETTINGS = API_LINK + ACCOUNT + "settings.json";

	};
	
};

#endif