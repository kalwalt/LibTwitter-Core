#ifndef H_TWITTERREQUEST_H
#define H_TWITTERREQUEST_H

#include <pthread.h>

#include <string>
#include <iostream>
#include <map>
#include <set>

class TwitterSession;
class TwitterRequestListener;

#include "CurlProcess.h"


/**
* \class TwitterRequest TwitterRequest.h
*
* \brief Represents a Twitter Request, used to communicate with Twitter API
* A TwitterRequest is linked with a TwitterSession in order to authenticate the user
*/
class TwitterRequest : public CurlProcess {
public:

	/**
	* \fn TwitterRequest
	* \brief Contructor. Requires a TwitterSession. 
	* An URL can be passed directly in constructor.
	*
	* \param session TwitterSession associated with this request
	* \param url Optional URL target for the request. If not defined, 
	* an URL MUST BE defined before sending, via set_url(url)
	*
	*/
	TwitterRequest( TwitterSession* session, const std::string& url = "" );

	/**
	* \fn ~TwitterRequest
	* \brief Destructor. Eliminates object, closes connection,
	* and erases all received data.
	*
	*/
	~TwitterRequest();

	//bool set_authentification( std::string user, std::string password );

	/**
	* \fn get_session
	* \brief Gets the TwitterSession associated to this TwitterRequest
	* 
	* \return Content of _session
	*/
	TwitterSession* get_session();

	/**
	* \fn get_response_data
	* \brief Gets data received from Twitter
	*
	* \return Content of _response_data
	*/
	std::string get_response_data();

	/**
	* \fn add_listener
	* \brief Adds a new TwitterRequestListener to request
	*
	* \param listener A subclass of TwitterRequestListener
	*
	* If no listener is defined, the main TwitterSession will be used as listener
	*
	*/
	void add_listener( TwitterRequestListener* listener );

	/**
	* \fn remove_listener
	* \brief Detach a TwitterRequestListener from request
	*
	* \param listener An attached subclass of TwitterRequestListener
	*
	*/
	void remove_listener( TwitterRequestListener* listener );


	/**
	* \fn add_form_file
	* \brief Adds a file in multipart upload list. (ex : uploading an image with status)
	*
	* \param field_name Name of the form field
	* \param file_path Path to the file to upload
	*
	*/
	void add_form_file( const std::string& field_name, const std::string& file_path );

	/**
	* \fn add_form_data
	* \brief Adds data to a HTTP multipart form. Replaces "POST" data in uploading requests
	*
	* \param field_name Name of the form field
	* \param value Associated data
	*
	*/
	void add_form_data( const std::string& field_name, const std::string& value );

protected:

	/**
	* \fn on_data_received 
	* \brief Called automatically when data/response is received
	*
	* \param data Content of received data
	*/
	virtual void on_data_received( const std::string& data );

	/**
	* \fn on_connection_closed 
	* \brief Called automatically when connection is closed
	*
	* \param response_code Reponse code of the HTTP request
	*/
	virtual void on_connection_closed( unsigned long response_code );

	/** 
	* \fn prepare
	* \brief Called automatically when request is sent.
	* In TwitterRequest, this method calls set_oauth_header()
	*/
	void prepare();


private:

	/** 
	* \fn set_oauth_header
	* \brief Defines the OAuth HTTP Header used for authentication
	* In TwitterRequest, this method is called automatically (via prepare())
	*
	* \param header OAuth Header to set.
	*/
	void set_oauth_header( const std::string& header );

	/**
	* \fn _on_data_received 
	* \brief Overloads method of CurlProcess base.
	*
	* \param data Autofilled parameter containing received data
	*
	* In TwitterRequest, this method concatenate receive data to _response_data
	* and calls recursively "on_data_received(data)" of TwitterRequest.
	*
	*/
	void _on_data_received( const std::string& data );

	/**
	* \fn _on_connection_closed 
	* \brief Overloads method of CurlProcess base.
	*
	* \param response_code Autofilled parameter containing response code
	*
	* In TwitterRequest, this method calls recursively "on_connection_closed(response_code)" of TwitterRequest.
	*
	*/
	void _on_connection_closed( unsigned long response_code );


	/** Attributes **/
	std::set<TwitterRequestListener*> _listeners;
	
	TwitterSession* _session;

	std::string _response_data;


	pthread_mutex_t _data_mutex_rw;

	curl_httppost* _form_post;
	curl_httppost* _form_end;


};


#endif