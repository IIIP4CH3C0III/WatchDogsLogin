#include "login.h"

// TODO

struct pam_response *response;

int 
pam_conversation( 
                 int num_msg, 
                 const struct pam_message **msg, 
                 struct pam_response **resp, 
                 void *appdata_ptr) {
    *resp = response;
    return PAM_SUCCESS;
}

bool 
login ( char * username , char * password ) {
	move( LINES - 1 , 1 );

	const struct pam_conv local_conversation = { pam_conversation , NULL };
	pam_handle_t *local_auth_handle = NULL; // this gets set by pam_start

	int pamResult;
	// local_auth_handle gets set based on the service
	pamResult = pam_start("common-auth", username, &local_conversation, &local_auth_handle);

    if ( pamResult != PAM_SUCCESS) {
        pam_end(local_auth_handle, pamResult);
        return false; // PAM initialization failed
    }

	response = (struct pam_response *)malloc( sizeof(struct pam_response) );

	response[0].resp = strdup( password );
	response[0].resp_retcode = 0;

	pamResult = pam_authenticate(local_auth_handle, 0);

	if (pamResult != PAM_SUCCESS)
	    if (pamResult == PAM_AUTH_ERR) {
        	pam_end(local_auth_handle, pamResult);
        	return false; // PAM initialization failed
    	}	

	pamResult = pam_end(local_auth_handle, pamResult);
    if ( pamResult != PAM_SUCCESS) {
        pam_end(local_auth_handle, pamResult);
        return false; // PAM initialization failed
    }

	return true;
}

/*
    if ( ( response = ( struct pam_response * )  malloc ( num_msg * sizeof(struct pam_response) ) ) == NULL )
        return PAM_BUF_ERR;

    for (int i = 0; i < num_msg; i++) 
    	switch ( msg[i]->msg_style ) {
    		case PAM_PROMPT_ECHO_OFF:
	            response[i].resp = strdup(password);  // Duplicate the password to response
	            response[i].resp_retcode = 0;         // Its not used so should be set to 0    		
    			break;
    		
    		case PAM_PROMPT_ECHO_ON :
	            response[i].resp = strdup(username);  
	            response[i].resp_retcode = 0;             		
    			break;

    		case PAM_ERROR_MSG      :
	            response[i].resp = NULL;
	            response[i].resp_retcode = PAM_SUCCESS;
    			break;
    			
    		case PAM_TEXT_INFO      :
    			break;
    	}
    	
    *resp = response;
*/


/*
    const char   * service     = "LoginWD"; // Replace with the appropriate PAM service name
	const char   * envArgs[2]  = { username , password };
    pam_handle_t * pamHandle   = NULL;
	

    struct pam_conv pamConverstation = { pam_conversation , &envArgs } ;
    int pamResult;

    // Set up the PAM conversation structure
    pamConverstation.conv = NULL; // Use default conversation function

    // Start the PAM session
    pamResult = pam_start(service , username, &pamConverstation, &pamHandle );
    if ( pamResult != PAM_SUCCESS) {
        pam_end(pamHandle, pamResult);
        return false; // PAM initialization failed
    }

    // Set the user-provided password for authentication
    pamResult = pam_set_item(pamHandle, PAM_AUTHTOK, password);
    if ( pamResult != PAM_SUCCESS ) {
        pam_end(pamHandle, pamResult);
        return false; // Setting password failed
    }

    // Authenticate the user
    pamResult = pam_authenticate(pamHandle , 0);
    if ( pamResult != PAM_SUCCESS ) {
        pam_end(pamHandle, pamResult);
        return false; // Authentication failed
    }

    // Check if the account is valid (optional)
    pamResult = pam_acct_mgmt(pamHandle, 0);
    if (pamResult != PAM_SUCCESS) {
        pam_end(pamHandle, pamResult);
        return false; // Account is not valid (e.g., expired, locked, etc.)
    }

    // Authentication and account checks passed
    pam_end(pamHandle, PAM_SUCCESS);
    return true;
 
*/
