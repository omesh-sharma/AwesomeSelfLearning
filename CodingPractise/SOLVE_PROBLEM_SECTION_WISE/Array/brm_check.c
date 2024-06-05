////
//// Created by omesh sharma on 22-08-2023.
////
//void
//pcp_open(
//        pcp_context_t**     ctxpp,  /* this should return this */
//        int32               flags,
//        pcp_fld_list_t*     flistp, /* input for pcp_login - NAP only */
//        int*                sockp,  /* NCP/NAP return socket descriptor */
//        /* CM input socket descriptor */
//        pin_errbuf_t*       ebufp)
//{
//    pcp_context_t*      ctxp;
//    int                 i;
//    char*               prog = NULL;		/* XXX? used */
//    char*               dbg;
//    char                emsg[128];
//    int32*              cfg_int_ptr = NULL;
//    char*               cfg_str_ptr = NULL;
//    int32*              utf8_ptr = NULL;
//    int32               err;
//    void			    *vp;
//    int     			line = 0;
//    time_t 				modt = (time_t)0;
//    time_t				now = 0;
//
//    /*
// * Initialize (once) the debug flags etc.
// */
//    if (ctxpp != NULL) {
//        *ctxpp = NULL;
//    }
//    pthread_once(&g_init_guard, pcp_initialize);
//    prog = pcp_get_prog_for_connection_type(flags, "pcp_open");
//    if (prog == NULL) {
//        ebufp->pin_err = PIN_ERR_BAD_ARG;
//        ebufp->reserved = 0;
//        return;
//    }
//
//    /* Initialize utf8 flag for Server */
//    /* Check to see if utf8 needs to be used*/
//    pin_conf(prog, "pcp_validate_string_fields_as_utf8", PIN_FLDT_INT,
//             (caddr_t *)&utf8_ptr, &err);
//
//    if (err == PIN_ERR_NONE && utf8_ptr) {
//        /* Set the global value */
//        if(*utf8_ptr == 0) {
//            useUTF8Validation = 0;
//        }
//        if(pcp_debug & PCP_DBG_OPEN) {
//            pin_snprintf(emsg, sizeof(emsg), "Program (%s) pcp_validate_string_fields_as_utf8=%d", prog , *utf8_ptr);
//            pinlog(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_DEBUG, emsg);
//        }
//        free(utf8_ptr);
//    }
//    ctxp = (pcp_context_t *)pin_malloc(sizeof(pcp_context_t));
//    if (ctxp == (pcp_context_t *)NULL) {
//        ebufp->pin_err = PIN_ERR_NO_MEM;
//        ebufp->reserved = 4;
//        return;
//    }
//    (void)memset((char *)ctxp, 0, sizeof(pcp_context_t));
//
//    /* set the connection state to initialized */
//    ctxp->connection_state = PCP_CTX_READY;
//    ctxp->wait_on_client_trans = 0;
//    ctxp->timeout_lock_override = 0;
//    ctxp->trans_state = 0;
//    ctxp->trans_type = 0;
//    ctxp->lock_type = 0;
//    ctxp->reconnect_retries = 0;
//
//
//    /* Set the fd to -1 so close doesn't try to do anything with it
//    */
//    ctxp->fd = -1;
//    ctxp->open_flag = flags;
//
//#if defined(INCL_SSL_)
//    #if defined(FOR_CM) || defined(FOR_PORTAL) || defined(FOR_DM) || defined(FOR_QM)
//	ctxp->psc = NULL;
//	ctxp->ssl_flags = PCP_SSL_NONE;
//	ctxp->ssl_cipher = NULL;
//	ctxp->ssl_server_globalp = NULL;
//	ctxp->ssl_client_globalp = NULL;
//#endif
//#endif
//
//    /* Seed the random number sequence */
//    ctxp->random_int = get_random_seed();
//
//    pcp_ssl_client_initialize(ctxp, prog, (pin_flist_t *)flistp, ebufp);
//    if (PIN_ERR_IS_ERR(ebufp)) {
//        pcp_close(ctxp, 0, 0);
//        return;
//    }
//
//    pcp_ssl_server_initialize(ctxp, prog, ebufp);
//    if (PIN_ERR_IS_ERR(ebufp)) {
//        pcp_close(ctxp, 0, 0);
//        return;
//    }
//
//    /* XXX HARDWIRED for now, and maybe forever */
//    ctxp->transport_type = USE_SOCKET;
//    /*
//     * Must be enough space for sockaddr_in or sockaddr_un.
//     * sockaddr_un is larger.
//     */
//    ctxp->transport_info = (caddr_t)pin_malloc(sizeof(struct sockaddr_storage));
//    ctxp->transport_infolen = 0;
//    if (ctxp->transport_info == (caddr_t)NULL) {
//        ebufp->pin_err = PIN_ERR_NO_MEM;
//        pcp_close(ctxp, 0, 0);
//        ctxp = NULL;
//        ebufp->reserved = 5;
//        return;
//    }
//    /* Set it to null so we know if we are connecting for the first
//     * time or are re-connecting
//     */
//    memset((char *)ctxp->transport_info, 0, sizeof(struct sockaddr_storage));
//
//    /* XXX must be multiple of 8 bytes for crypt */
//    /* XXX HARDCODED - always starts at 4K, since this is the original
//     * protocol size. If the other side responds with it handles larger
//     * blocks, then subsequent operations use the larger size
//     */
//    ctxp->max_chunk = PCP_DEFAULT_MAX_CHUNK;
//
//    /* XXX HARDCODED - always starts at 8 bytes */
//    ctxp->sig_pad = 8;
//
//    ctxp->login_session_id = 1;	/* HARDCODE XXX; */
//    /* XXX this should come from the state file */
//
//    /* Check for retry values */
//    /*
//     * Check for pcm_connect_max_retries
//     */
//
//    pin_conf(prog, "pcm_connect_max_retries", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->pcm_connect_max_retries = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcm_connect_max_retries=%d", ctxp->pcm_connect_max_retries);
//    }
//    else {
//        ctxp->pcm_connect_max_retries = 1;	/* Default value */
//    }
//
//    pin_conf("-", "refresh_interval", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->refresh_interval = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        now = pin_virtual_time(NULL);
//        ctxp->start_time = now;
//    } else {
//        ctxp->refresh_interval = 0;
//        now = pin_virtual_time(NULL);
//        ctxp->start_time = now;
//    }
//    pin_conf("-", "pcp_reconnect_delay_on_socket_error", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->pcp_reconnect_delay_on_socket_error = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcp_reconnect_delay_on_socket_error=%d",
//                ctxp->pcp_reconnect_delay_on_socket_error);
//    } else {
//        ctxp->pcp_reconnect_delay_on_socket_error = 0;
//    }
//
//    pin_conf("-", "pcp_connect_retry_delay_on_error", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->pcp_connect_retry_delay_on_error = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcp_connect_retry_delay_on_error=%d",
//                ctxp->pcp_connect_retry_delay_on_error);
//    } else {
//        ctxp->pcp_connect_retry_delay_on_error = 0;
//    }
//
//    /*
//     * Check for pcm_reconnect_max_retries
//     */
//
//    pin_conf(prog, "pcm_reconnect_max_retries", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->pcm_reconnect_max_retries = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcm_reconnect_max_retries=%d",
//                ctxp->pcm_reconnect_max_retries);
//    }
//    else {
//        ctxp->pcm_reconnect_max_retries = 3;	/* Default value */
//    }
//    /*
//     * Check for pcm_op_max_retries
//     */
//
//    pin_conf(prog, "pcm_op_max_retries", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->pcm_op_max_retries = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcm_op_max_retries=%d", ctxp->pcm_op_max_retries);
//    }
//    else {
//        ctxp->pcm_op_max_retries = 0;	/* Default value */
//    }
//    /*
//     * Check for pcm_op_timeout_max_retries
//     */
//
//    pin_conf(prog, "pcm_op_timeout_max_retries", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->pcm_op_timeout_max_retries = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcm_op_timeout_max_retries=%d",
//                ctxp->pcm_op_timeout_max_retries);
//    }
//    else {
//        ctxp->pcm_op_timeout_max_retries = 0;	/* Default value */
//    }
//    /*
//     * Check for pcm_reconnect: first (0) or next (1)
//     */
//
//    pin_conf(prog, "pcm_reconnect", PIN_FLDT_STR,
//             (caddr_t *)(&cfg_str_ptr), &err);
//    if (err == PIN_ERR_NONE) {
//        if (strcasecmp(cfg_str_ptr, "first") == 0) {
//            ctxp->pcm_reconnect = 0;
//        }
//        else if (strcasecmp(cfg_str_ptr, "next") == 0) {
//            ctxp->pcm_reconnect = 1;
//        }
//        else {
//            ebufp->pin_err = PIN_ERR_INVALID_CONF;
//            pcp_close(ctxp, 0, 0);
//            ctxp = NULL;
//            ebufp->reserved = 112;
//            free(cfg_str_ptr);
//            cfg_str_ptr = NULL;
//            return;
//            /*****/
//        }
//        free(cfg_str_ptr);
//        cfg_str_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcm_recconect=%d", ctxp->pcm_reconnect);
//    }
//    else {
//        ctxp->pcm_reconnect = 0;	/* Default value */
//    }
//
//    /***********************************************************
//     * first check to see if the input flist specified an
//     * override timeout.  This will normally only be used
//     * by some NAP's in libportal, but avoid ifdef complexity
//     * here
//     ***********************************************************/
//
//    vp = NULL;
//    if (flistp) {
//        vp = PIN_FLIST_FLD_GET((pin_flist_t *)flistp,
//                               PIN_FLD_TIMEOUT_IN_MS, 1, ebufp);
//    }
//    if (vp) {
//        ctxp->pcm_timeout_in_msecs = *((int32 *)vp);
//    }
//    else {
//
//        /*
//         * Check for pcm_timeout_in_msecs
//         */
//
//        pin_conf(prog, "pcm_timeout_in_msecs", PIN_FLDT_INT,
//                 (caddr_t *)&cfg_int_ptr, &err);
//        if (err == PIN_ERR_NONE) {
//            /* Set the global value */
//            ctxp->pcm_timeout_in_msecs = *cfg_int_ptr;
//            free(cfg_int_ptr);
//            cfg_int_ptr = NULL;
//            pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                    "pcp_open(), set pcm_timeout_in_msecs=%d", ctxp->pcm_timeout_in_msecs);
//        }
//        else {
//            ctxp->pcm_timeout_in_msecs = -1; /* Default value */
//        }
//    }
//
//    /*
//
//     */
//    vp = NULL;
//    if (flistp) {
//        vp = PIN_FLIST_FLD_GET((pin_flist_t *)flistp,
//                               PIN_FLD_AUTO_RECONNECT, 1, ebufp);
//    }
//    if (vp) {
//        ctxp->pcm_auto_reconnect = *((int32 *)vp);
//    }
//    else {
//
//        /*
//         * Check for pcm_auto_reconnect
//         */
//
//        pin_conf(prog, "pcm_auto_reconnect", PIN_FLDT_INT,
//                 (caddr_t *)&cfg_int_ptr, &err);
//        if (err == PIN_ERR_NONE) {
//            /* Set the global value */
//            ctxp->pcm_auto_reconnect = *cfg_int_ptr;
//            free(cfg_int_ptr);
//            cfg_int_ptr = NULL;
//        }
//        else {
//            ctxp->pcm_auto_reconnect = 1; /* Default value */
//        }
//    }
//    /* Ignore wrong values to pcm_auto_reconnect */
//    if(ctxp->pcm_auto_reconnect != 1 && ctxp->pcm_auto_reconnect != 0) {
//        ctxp->pcm_auto_reconnect = 1;
//    }
//
//    /* Debug auto-reconnect values */
//    if (ctxp->pcm_auto_reconnect != 1 && ctxp->pcm_auto_reconnect != 0) {
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), pcm_auto_reconnect should be set 0 or 1");
//    } else {
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), pcm_auto_reconnect is %d", ctxp->pcm_auto_reconnect);
//    }
//
//    /*
//     * Check for pcm_suspect_timeout_in_msecs
//     */
//
//    pin_conf(prog, "pcm_suspect_timeout_in_msecs", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global long timeout in secs value */
//        ctxp->pcm_suspect_timeout_in_msecs = *cfg_int_ptr;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcm_suspect_timeout_in_msecs=%d",
//                ctxp->pcm_suspect_timeout_in_msecs);
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//    }
//    else {
//        /* If this parameter is not specified, then set to -1 so
//         * that other code will know to NOT use dual timeout mode
//         */
//        ctxp->pcm_suspect_timeout_in_msecs= -1;   /* Default value */
//    }
//
//    /*
//     * Check for pcm_bad_connection_retry_delay_time_in_secs
//     */
//    pin_conf(prog, "pcm_bad_connection_retry_delay_time_in_secs", PIN_FLDT_INT,
//             (caddr_t *)&cfg_int_ptr, &err);
//    if (err == PIN_ERR_NONE) {
//        /* Set the global value */
//        ctxp->pcm_connect_retry_delay_time_in_secs = *cfg_int_ptr;
//        free(cfg_int_ptr);
//        cfg_int_ptr = NULL;
//        pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                "pcp_open(), set pcm_bad_connection_retry_delay_time_in_secs=%d",
//                ctxp->pcm_connect_retry_delay_time_in_secs);
//    }
//    else {
//        ctxp->pcm_connect_retry_delay_time_in_secs = 0;	/* Default value */
//    }
//
//    ctxp->connect_timeout_in_msecs = get_int_pin_conf(prog, "connect_timeout_in_msecs", -1, pcp_debug & PCP_DBG_OPEN, "pcp_open()");
//
//    /*
//     * Note:
//     * For a type 0 login where login flist is not passed in, the
//     * the userid is read from pin.conf on NAP connection in
//     * make_type_0_login_flist() in pcp_login.c.
//     */
//    if (flags & PCP_OPEN_NMGR) {
//        ctxp->user = pin_poid_from_str("0.0.0.0 /infmgr_client 1",
//                                       (char **) NULL, ebufp);
//        if (ebufp->pin_err != PIN_ERR_NONE) {
//            /* Print the entire message at once so the output isn't
//            * intermixed with the output from other processes/threads
//            */
//            pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                    "pcp_open: error in pin_poid_from_str, err %d", ebufp->pin_err);
//            pcp_close(ctxp, 0, 0);
//            ctxp = NULL;
//            ebufp->reserved = 100;
//            return;
//            /**********/
//        }
//    }
//
//    ctxp->crypt_type = CRYPT_TYPE_NONE;
//    ctxp->crypt_data = (caddr_t)0;		/*XXX;*/
//    ctxp->sig_type = SIG_TYPE_NONE;
//    ctxp->sig_size = 0;
//    ctxp->sig_data = (caddr_t)0;
//
//    /* fill in private fields for lower layer */
//    pcpxdr_ctx_finish(ctxp);
//
//    if ((flags & (PCP_OPEN_NAP)) || (flags & (PCP_OPEN_NMGR))) {
//        /*
//         * do connect and login to the CM.
//         * stash input flist in context
//         */
//        ctxp->login_flist = (pcp_fld_list_t *)pin_flist_copy(
//                (pin_flist_t *)(flistp), ebufp);
//        if (ebufp->pin_err != PIN_ERR_NONE) {
//            /* should "never" happen */
//            pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                    "bad flist copy in pcp_open(), pin_err=%d(%-.50s)",
//                    ebufp->pin_err, pin_pinerr_to_str(ebufp->pin_err));
//            pcp_close(ctxp, 0, 0);
//            ctxp = NULL;
//            ebufp->reserved = 6;
//            return;
//            /******/
//        }
//    }
//
//    /* do connection to DM only if ctxp->current_dm is not 0 */
//    if ((flags & (PCP_OPEN_NAP)) || (flags & (PCP_OPEN_NMGR)) ||
//        (((flags & (PCP_OPEN_CM2DM)) || (flags & (PCP_OPEN_DM2DM))) &&
//         ctxp->current_dm != 0) ||
//        ((flags & PCP_OPEN_CM2EM) && strlen(ctxp->current_em) > 0)) {
//
//        pcp_connect(ctxp, ebufp);
//
//        if (ebufp->pin_err != PIN_ERR_NONE) {
//            if (ebufp->pin_err != PIN_ERR_NONE) {
//                pcp_log(PIN_FILE_SOURCE_ID, __LINE__, LOG_FLAG_NONE, PCP_DBG_OPEN,
//                        "login failed, pin_err=%d(%-.50s)",
//                        ebufp->pin_err, pin_pinerr_to_str(ebufp->pin_err));
//                pcp_close(ctxp, 0, 0);
//                ctxp = NULL;
//                return;
//            }
//        }
//
//        /* else CM, DM will set ctxp->fd and peername */
//        if ((flags & (PCP_OPEN_CM2NP | PCP_OPEN_DM | PCP_OPEN_BIDIR)) ||
//            (((flags & (PCP_OPEN_CM2DM)) || (flags & (PCP_OPEN_DM2DM))) &&
//             ctxp->current_dm == 0) ||
//            ((flags & PCP_OPEN_CM2EM) && strlen(ctxp->current_em) == 0)) {
//            /* PCP_OPEN_CM ... means have to fill in fd, ... */
//
//            ctxp->fd = *sockp;
//        }
//
//        ctxp->proto_vers = 0; /* Old dumb protocol */
//        ctxp->session_id = 0;
//
//        *ctxpp = ctxp;
//        if (sockp != (int *)NULL) {
//            *sockp = ctxp->fd;
//        }
//
//        /*
//         * If necessary, do server to client hanshake ...
//         */
//        pcp_ssl_server_handshake(ctxp, ebufp);
//        if (PIN_ERR_IS_ERR(ebufp)) {
//            return;
//        }
//
//        ebufp->pin_err = PIN_ERR_NONE;
//        return;
//    }


// crt_strncpy_x86.c
// Use this command in an x86 developer command prompt to compile:
// cl /TC /W3 crt_strncpy_x86.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char t[20];
    char s[20];
    char *p = 0, *q = 0;

    strcpy_s(s, sizeof(s), "AA BB CC");
    // Note: strncpy is deprecated; consider using strncpy_s instead
    strncpy(s, "aa", 2);     // "aa BB CC"         C4996
    strncpy(s + 3, "bb", 2); // "aa bb CC"         C4996
    strncpy(s, "ZZ", 3);     // "ZZ",              C4996
    // count greater than strSource, null added
    printf("%s\n", s);

    strcpy_s(s, sizeof(s), "AA BB CC");
    p = strstr(s, "BB");
    q = strstr(s, "CC");
    strncpy(s, "aa", p - s - 1);   // "aa BB CC"   C4996
    strncpy(p, "bb", q - p - 1);   // "aa bb CC"   C4996
    strncpy(q, "cc",  q - s);      // "aa bb cc"   C4996
    strncpy(q, "dd", strlen(q));   // "aa bb dd"   C4996
    printf("%s\n", s);

    // some problems with strncpy
    strcpy_s(s, sizeof(s), "test");
    strncpy(t, "this is a very long string", 20 ); // C4996
    // Danger: at this point, t has no terminating null,
    // so the printf continues until it runs into one.
    // In this case, it will print "this is a very long test"
    printf("%s\n", t);

    strcpy_s(t, sizeof(t), "dogs like cats");
    printf("%s\n", t);

    strncpy(t + 10, "to chase cars.", 14); // C4996
    printf("%s\n", t);

    // strncpy has caused a buffer overrun and corrupted string s
    printf("Buffer overrun: s = '%s' (should be 'test')\n", s);
    // Since the stack grows from higher to lower addresses, buffer
    // overruns can corrupt function return addresses on the stack,
    // which can be exploited to run arbitrary code.
}